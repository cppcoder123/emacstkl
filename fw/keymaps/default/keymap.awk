# C - left: Caps Lock, right/middle: Ctrl
#
# C-` C-x 0
# C-1 C-x 1
# C-2 C-x 2
# C-3 C-x 3
# C-c M-x "compile"
# C-r M-x "recompile"
# C-o C-x C-f
# C-s C-x C-s
# C-g M-x "magit"
# C-m "make"       ; terminal
# C-j "make -j "   ; terminal
# C-l "make clean" ; terminal
# C-e C-x `        ; next-error
# C-h              ; shift-insert for terminal
# ...

# add dst to arr-dst using index derived by src in ar_src search
function map (ar_src, ar_dst, src, dst)
{
    for (i = 1; i <= length (ar_src); i++) {
        if (ar_src[i] == src) {
            ar_dst[i] = dst;
            break;
        }
    }
}

function define_layer (layer_id, layer_info)
{
    print "#define " layer_id " LAYOUT_tkl_ansi( \\"
    for (i = 1; i <= length (layer_info); i++) {
        info = layer_info[i]
        if (i < length (layer_info))
            print "  " info ", \\"
        else
            print "  " info ")"
    }
}

function print_map (layer_a, layer_b)
{
    print "/*"
    for (i = 1; i <= length (layer_a); i++) {
        print "  " layer_a[i] " -> " layer_b[i]
    }
    print "*/"
}

BEGIN {
    src =                                                               \
        "KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8," \
        "KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS,"     \
        "KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0," \
        "KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP,"           \
        "KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P," \
        "KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN,"           \
        "KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L," \
	"KC_SCLN, KC_QUOT, KC_ENT,"					\
        "KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT," \
        "KC_SLSH, KC_RSFT, KC_UP,"                                      \
        "KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_F20,"	\
	"KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT"

    # replace comma in braces with '|'
    #tmp = gensub (/(\([^ ,]+)[ ]*,[ ]*([^)]+\))/, "\\1|\\2", "g", src)
    # make an array
    split (src, layer_base, "(,)|(, )|(,\n)")

    # form home-row & extra layers
    for (i = 1; i <= length (layer_base); i++) {
        layer_home_row[i] = "KC_TRNS";
        layer_tmux[i] = "KC_NO";
        layer_emacs[i] = "KC_NO";
    }

    #
    map(layer_base, layer_tmux, "KC_SCRL", "QK_BOOT")
    #
    map(layer_base, layer_tmux, "KC_0", "M_TMUX_WIN_0")
    map(layer_base, layer_tmux, "KC_1", "M_TMUX_WIN_1")
    map(layer_base, layer_tmux, "KC_2", "M_TMUX_WIN_2")
    map(layer_base, layer_tmux, "KC_3", "M_TMUX_WIN_3")
    map(layer_base, layer_tmux, "KC_4", "M_TMUX_WIN_4")
    map(layer_base, layer_tmux, "KC_5", "M_TMUX_WIN_5")
    map(layer_base, layer_tmux, "KC_6", "M_TMUX_WIN_6")
    map(layer_base, layer_tmux, "KC_7", "M_TMUX_WIN_7")
    map(layer_base, layer_tmux, "KC_8", "M_TMUX_WIN_8")
    map(layer_base, layer_tmux, "KC_9", "M_TMUX_WIN_9")
    map(layer_base, layer_tmux, "KC_C", "M_TMUX_WIN_NEW")
    map(layer_base, layer_tmux, "KC_COMM", "M_TMUX_WIN_NAME")
    map(layer_base, layer_tmux, "KC_DOT", "M_TMUX_WIN_NUMBER")
    map(layer_base, layer_tmux, "KC_DOWN", "M_TMUX_PANE_FOCUS_DOWN")
    map(layer_base, layer_tmux, "KC_EQL", "M_TMUX_COPY_MODE")
    map(layer_base, layer_tmux, "KC_F", "M_TMUX_WIN_FIND")
    map(layer_base, layer_tmux, "KC_F9", "M_TMUX_CTL_ALT_DEL")
    map(layer_base, layer_tmux, "KC_GRV", "M_TMUX_PANE_TO_WIN")
    map(layer_base, layer_tmux, "KC_H", "M_TMUX_SHIFT_INSERT")
    map(layer_base, layer_tmux, "KC_J", "M_TMUX_MAKE_J")
    map(layer_base, layer_tmux, "KC_K", "M_TMUX_PANE_KILL")
    map(layer_base, layer_tmux, "KC_L", "M_TMUX_MAKE_CLEAN")
    map(layer_base, layer_tmux, "KC_LBRC", "M_TMUX_PANE_MOVE_LEFT")
    map(layer_base, layer_tmux, "KC_LEFT", "M_TMUX_PANE_FOCUS_LEFT")
    map(layer_base, layer_tmux, "KC_M", "M_TMUX_MAKE")
    map(layer_base, layer_tmux, "KC_N", "M_TMUX_WIN_NEXT")
    map(layer_base, layer_tmux, "KC_P", "M_TMUX_WIN_PREV")
    map(layer_base, layer_tmux, "KC_QUOT", "M_TMUX_PANE_SPLIT_H")
    map(layer_base, layer_tmux, "KC_RIGHT", "M_TMUX_PANE_FOCUS_RIGHT")
    map(layer_base, layer_tmux, "KC_RBRC", "M_TMUX_PANE_MOVE_RIGHT")
    map(layer_base, layer_tmux, "KC_S", "M_TMUX_WIN_SELECT")
    map(layer_base, layer_tmux, "KC_SCLN", "M_TMUX_PANE_SPLIT_V")
    map(layer_base, layer_tmux, "KC_T", "M_TMUX_TIME")
    map(layer_base, layer_tmux, "KC_UP", "M_TMUX_PANE_FOCUS_UP")
    map(layer_base, layer_tmux, "KC_W", "M_TMUX_WIN_LIST")
    #
    define_layer("EMACSTKL_INFO_TMUX", layer_tmux)
    print_map(layer_base, layer_tmux)
    #
    #
    map(layer_base, layer_emacs, "KC_1", "M_EMACS_BUFFER_1")
    map(layer_base, layer_emacs, "KC_2", "M_EMACS_BUFFER_2")
    map(layer_base, layer_emacs, "KC_3", "M_EMACS_BUFFER_3")
    map(layer_base, layer_emacs, "KC_A", "M_EMACS_AVY_GOTO_CHAR_TIMER")
    map(layer_base, layer_emacs, "KC_C", "M_EMACS_COMPILE")
    map(layer_base, layer_emacs, "KC_E", "M_EMACS_NEXT_ERROR")
    map(layer_base, layer_emacs, "KC_ESC", "M_EMACS_WIN_JUMP")
    map(layer_base, layer_emacs, "KC_F1", "M_EMACS_WIN_1")
    map(layer_base, layer_emacs, "KC_F2", "M_EMACS_WIN_2")
    map(layer_base, layer_emacs, "KC_F3", "M_EMACS_WIN_3")
    map(layer_base, layer_emacs, "KC_F4", "M_EMACS_WIN_4")
    map(layer_base, layer_emacs, "KC_G", "M_EMACS_DYNAMIC_EXPAND")
    map(layer_base, layer_emacs, "KC_GRV", "M_EMACS_BUFFER_0")
    map(layer_base, layer_emacs, "KC_H", "M_EMACS_HIPPIE_EXPAND")
    map(layer_base, layer_emacs, "KC_M", "M_EMACS_MAGIT")
    map(layer_base, layer_emacs, "KC_O", "M_EMACS_FILE_OPEN")
    map(layer_base, layer_emacs, "KC_R", "M_EMACS_COMPILE_AGAIN")
    map(layer_base, layer_emacs, "KC_S", "M_EMACS_FILE_SAVE")
    map(layer_base, layer_emacs, "KC_W", "M_EMACS_BUFFER_SWITCH")
    #
    define_layer("EMACSTKL_INFO_EMACS", layer_emacs)
    print_map(layer_base, layer_emacs)

    # fill layer_home_row
    #map(layer_base, layer_home_row, "KC_A", "MT(MOD_LGUI, KC_A)")
    map(layer_base, layer_home_row, "KC_S", "MT(MOD_LSFT, KC_S)")
    map(layer_base, layer_home_row, "KC_D", "MT(MOD_LALT, KC_D)")
    map(layer_base, layer_home_row, "KC_F", "MT(MOD_LCTL, KC_F)")
    map(layer_base, layer_home_row, "KC_J", "MT(MOD_RCTL, KC_J)")
    map(layer_base, layer_home_row, "KC_K", "MT(MOD_RALT, KC_K)")
    map(layer_base, layer_home_row, "KC_L", "MT(MOD_RSFT, KC_L)")
    #map(layer_base, layer_home_row, "KC_SCLN", "MT(MOD_LGUI, KC_SCLN)")
    #
    # layer: home-row -> emacs
    map(layer_base, layer_home_row, "KC_A", "LT(EMACSTKL_LAYER_EMACS, KC_A)")
    map(layer_base, layer_home_row, "KC_SCLN", "LT(EMACSTKL_LAYER_EMACS, KC_SCLN)")
    # layer: home-row -> tmux
    # caps should work
    #map(layer_base, layer_home_row, "KC_SPC", "LT(EMACSTKL_LAYER_TMUX)")
    #
    define_layer("EMACSTKL_INFO_HOME_ROW", layer_home_row)
    print_map(layer_base, layer_home_row)

    # Base layer modification, keep at min:
    #
    # base -> home-row, toggle
    map(layer_base, layer_base, "KC_F5", "TG(EMACSTKL_LAYER_HOME_ROW)")
    # base -> tmux, keep the button pressed
    map(layer_base, layer_base, "KC_CAPS", "LT(EMACSTKL_LAYER_TMUX, KC_NO)")
    #
    define_layer("EMACSTKL_INFO_BASE", layer_base)

    exit
}
