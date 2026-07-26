/*
 *
 */

void keyboard_pre_init_user ()
{
  gpio_set_pin_output (EMACSTKL_LED_HOME_ROW);
  gpio_set_pin_output (EMACSTKL_LED_EMACS);
  gpio_set_pin_output (EMACSTKL_LED_TMUX);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_HOME_ROW))
    gpio_write_pin_high (EMACSTKL_LED_HOME_ROW);
  else
    gpio_write_pin_low (EMACSTKL_LED_HOME_ROW);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_EMACS))
    gpio_write_pin_high (EMACSTKL_LED_EMACS);
  else
    gpio_write_pin_low (EMACSTKL_LED_EMACS);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_TMUX))
    gpio_write_pin_high (EMACSTKL_LED_TMUX);
  else
    gpio_write_pin_low (EMACSTKL_LED_TMUX);

  return state;
}

