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
        layer_extra[i] = "KC_NO";
    }

    # fill layer extra
    ####map(layer_base, layer_home_row, "KC_CAPS", "KC_NO")
    ####map(layer_base, layer_extra, "KC_LGUI", "KC_NO")
    #map(layer_base, layer_3, "KC_F20", "KC_NO")
    #
    map(layer_base, layer_extra, "KC_SCRL", "QK_BOOT")
    #
    map(layer_base, layer_extra, "KC_1", "MACRO_BUFFER_1")
    map(layer_base, layer_extra, "KC_2", "MACRO_BUFFER_2")
    map(layer_base, layer_extra, "KC_3", "MACRO_BUFFER_3")
    map(layer_base, layer_extra, "KC_A", "MACRO_AVY_GOTO_CHAR_TIMER")
    map(layer_base, layer_extra, "KC_C", "MACRO_COMPILE")
    map(layer_base, layer_extra, "KC_DOWN", "MACRO_TMUX_FOCUS_DOWN")
    map(layer_base, layer_extra, "KC_E", "MACRO_NEXT_ERROR")
    map(layer_base, layer_extra, "KC_ESC", "MACRO_WIN_JUMP")
    map(layer_base, layer_extra, "KC_F1", "MACRO_WIN_1")
    map(layer_base, layer_extra, "KC_F2", "MACRO_WIN_2")
    map(layer_base, layer_extra, "KC_F3", "MACRO_WIN_3")
    map(layer_base, layer_extra, "KC_F4", "MACRO_WIN_4")
    map(layer_base, layer_extra, "KC_F9", "MACRO_CTL_ALT_DEL")
    map(layer_base, layer_extra, "KC_G", "MACRO_MAGIT")
    map(layer_base, layer_extra, "KC_GRV", "MACRO_BUFFER_0")
    map(layer_base, layer_extra, "KC_H", "MACRO_SHIFT_INSERT")
    map(layer_base, layer_extra, "KC_J", "MACRO_MAKE_J")
    map(layer_base, layer_extra, "KC_L", "MACRO_MAKE_CLEAN")
    map(layer_base, layer_extra, "KC_LEFT", "MACRO_TMUX_FOCUS_PREV")
    map(layer_base, layer_extra, "KC_M", "MACRO_MAKE")
    map(layer_base, layer_extra, "KC_N", "MACRO_TMUX_NEW")
    map(layer_base, layer_extra, "KC_O", "MACRO_FILE_OPEN")
    map(layer_base, layer_extra, "KC_P", "MACRO_TMUX_SPLIT_H")
    map(layer_base, layer_extra, "KC_R", "MACRO_COMPILE_AGAIN")
    map(layer_base, layer_extra, "KC_RIGHT", "MACRO_TMUX_FOCUS_NEXT")
    map(layer_base, layer_extra, "KC_S", "MACRO_FILE_SAVE")
    map(layer_base, layer_extra, "KC_UP", "MACRO_TMUX_FOCUS_UP")
    map(layer_base, layer_extra, "KC_W", "MACRO_BUFFER_SWITCH")
    #
    define_layer("EMACSTKL_INFO_EXTRA", layer_extra)
    print_map(layer_base, layer_extra)

    # fill layer_home_row
    map(layer_base, layer_home_row, "KC_A", "MT(MOD_LGUI, KC_A)")
    map(layer_base, layer_home_row, "KC_S", "MT(MOD_LSFT, KC_S)")
    map(layer_base, layer_home_row, "KC_D", "MT(MOD_LALT, KC_D)")
    map(layer_base, layer_home_row, "KC_F", "MT(MOD_LCTL, KC_F)")
    map(layer_base, layer_home_row, "KC_J", "MT(MOD_RCTL, KC_J)")
    map(layer_base, layer_home_row, "KC_K", "MT(MOD_RALT, KC_K)")
    map(layer_base, layer_home_row, "KC_L", "MT(MOD_RSFT, KC_L)")
    map(layer_base, layer_home_row, "KC_SCLN", "MT(MOD_LGUI, KC_SCLN)")
    #
    define_layer("EMACSTKL_INFO_HOME_ROW", layer_home_row)
    print_map(layer_base, layer_home_row)

    #
    # define layer switch keys
    #
    # home-row -> extra
    #
    # home-row -> extra, momentarily
    # KC_NO is already on the target layer
    map(layer_base, layer_home_row, "KC_SPC", "LT(EMACSTKL_LAYER_EXTRA, KC_SPC)")
    # home-row -> base, toggle
    #map(layer_base, layer_base, "KC_F6", "KC_NO")
    #map(layer_base, layer_home_row, "KC_F6", "TG(EMACSTKL_LAYER_BASE)")
    #
    # base -> home-row, toggle
    map(layer_base, layer_home_row, "KC_F5", "KC_TRNS")
    map(layer_base, layer_base, "KC_F5", "TG(EMACSTKL_LAYER_HOME_ROW)")
    # base -> extra, momentarily
    # KC_NO is already there
    map(layer_base, layer_base, "KC_CAPS", "MO(EMACSTKL_LAYER_EXTRA)")
    #

    # define base layer here
    define_layer("EMACSTKL_INFO_BASE", layer_base)

    exit
}
