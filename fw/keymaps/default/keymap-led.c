/*
 *
 */

#include <deferred_exec.h>
#include <i2c_master.h>

#define LED_LAYER_EMACS (1 << 1)
#define LED_LAYER_TMUX (1 << 0)
#define LED_LAYER_MASK_ON (LED_LAYER_EMACS | LED_LAYER_TMUX)
#define LED_LAYER_MASK_OFF 0

#define LED_CHIP_ADDRESS 0x20
#define LED_WRITE_ADDRESS (LED_CHIP_ADDRESS << 1)

#define MSG_END 1
#define MSG_SWITCH_OFF 2
#define MSG_SWITCH_ON 3
#define MSG_WAIT_LESS 4
#define MSG_WAIT_MORE 5
/* on, wait, off, wait, on, wait, off, end => 8 */
#define MSG_LEN_MAX 8

#define HOME_ROW_OFF 0
#define HOME_ROW_ON 1

#define DELAY_LONG 600
#define DELAY_SHORT 300

static uint8_t msg[MSG_LEN_MAX];
static uint8_t msg_step = MSG_LEN_MAX;

static uint8_t home_row_state = HOME_ROW_ON;
static uint8_t emacs_tmux_state = 0;

static void keymap_led_execute (void);

static void keymap_led_write (uint8_t byte)
{
  /*1 sec timeout*/
  i2c_transmit (LED_WRITE_ADDRESS, &byte, 1, 1000);
}

uint32_t keymap_led_callback (uint32_t, void*)
{
  keymap_led_execute ();

  return 0;
}

static void keymap_led_execute (void)
{
  if (msg_step >= MSG_LEN_MAX)
    return;

  uint8_t current = msg[msg_step++];

  switch (current) {
  case MSG_SWITCH_ON:
  case MSG_SWITCH_OFF:
    keymap_led_write ((current == MSG_SWITCH_ON)
		      ? LED_LAYER_MASK_ON : LED_LAYER_MASK_OFF);
    keymap_led_execute ();
    break;
  case MSG_WAIT_LESS:
  case MSG_WAIT_MORE:
    defer_exec ((current == MSG_WAIT_LESS) ? DELAY_SHORT : DELAY_LONG,
		keymap_led_callback, NULL);
    break;
  case MSG_END:
    /*do nothing*/
    break;
  default:
    break;
  }
}

static void keymap_led_write_home_row (uint8_t on)
{
  uint8_t index = 0;

  if (on == HOME_ROW_ON) {
    msg[index++] = MSG_SWITCH_ON;
    msg[index++] = MSG_WAIT_LESS;
    msg[index++] = MSG_SWITCH_OFF;
    msg[index++] = MSG_WAIT_LESS;
    msg[index++] = MSG_SWITCH_ON;
    msg[index++] = MSG_WAIT_LESS;
    msg[index++] = MSG_SWITCH_OFF;
    msg[index++] = MSG_END;
  } else {
    msg[index++] = MSG_SWITCH_ON;
    msg[index++] = MSG_WAIT_MORE;
    msg[index++] = MSG_SWITCH_OFF;
    msg[index++] = MSG_END;
  }

  msg_step = 0;
  keymap_led_execute ();
}

void keyboard_pre_init_user (void)
{
  i2c_init ();

  keymap_led_write (0);
}

layer_state_t layer_state_set_user (layer_state_t state)
{
  uint8_t emacs_tmux = 0;

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_EMACS))
    emacs_tmux |= LED_LAYER_EMACS;

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_TMUX))
    emacs_tmux |= LED_LAYER_TMUX;

  if ((emacs_tmux != 0) || (emacs_tmux != emacs_tmux_state)) {
    keymap_led_write (emacs_tmux_state = emacs_tmux);
    return state;
  }

  uint8_t actual_state = (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_HOME_ROW))
    ? HOME_ROW_ON : HOME_ROW_OFF;

  if (home_row_state == actual_state)
    return state;

  keymap_led_write_home_row (home_row_state = actual_state);

  return state;
}
