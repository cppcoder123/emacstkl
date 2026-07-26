/*
 *
 */

#include <i2c_master.h>

/*01010101*/
#define MASK_ODD 85

/*10101010*/
#define MASK_EVEN 170

#define MASK_ZERO 0


#define LED_LAYER_EMACS (1 << 1)
#define LED_LAYER_HOME_ROW (1 << 7) /* invisible */
#define LED_LAYER_TMUX (1 << 0)

#define LED_CHIP_ADDRESS 0x20
#define LED_WRITE_ADDRESS (LED_CHIP_ADDRESS << 1)

static void keymap_led_write (uint8_t byte)
{
  /*1 sec timeout*/
  i2c_transmit (LED_WRITE_ADDRESS, &byte, 1, 1000);
}

void keyboard_pre_init_user ()
{
  i2c_init ();

  keymap_led_write (MASK_ODD);
  keymap_led_write (MASK_EVEN);
  keymap_led_write (MASK_ZERO);
}

layer_state_t layer_state_set_user (layer_state_t state)
{
  uint8_t msg = 0;

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_HOME_ROW))
    msg |= LED_LAYER_HOME_ROW;

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_TMUX))
    msg |= LED_LAYER_TMUX;

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_EMACS))
    msg |= LED_LAYER_EMACS;

  keymap_led_write (msg);

  return state;
}
