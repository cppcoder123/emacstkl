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
    split (src, layer_0, "(,)|(, )|(,\n)")

    # create empty layer 1
    for (i = 1; i <= length (layer_0); i++) {
        layer_1[i] = "KC_NO";
        # to debug l2 & l3 leds
        layer_2[i] = "KC_NO";
        layer_3[i] = "KC_NO";
    }

    # fill layer 1
    map(layer_0, layer_1, "KC_CAPS", "KC_TRNS")
    map(layer_0, layer_2, "KC_LGUI", "KC_TRNS")
    map(layer_0, layer_3, "KC_F20", "KC_TRNS")
    #
    map(layer_0, layer_1, "KC_SCRL", "QK_BOOT")
    #
    map(layer_0, layer_1, "KC_1", "MACRO_BUFFER_1")
    map(layer_0, layer_1, "KC_2", "MACRO_BUFFER_2")
    map(layer_0, layer_1, "KC_3", "MACRO_BUFFER_3")
    map(layer_0, layer_1, "KC_C", "MACRO_COMPILE")
    map(layer_0, layer_1, "KC_DOWN", "MACRO_TMUX_FOCUS_DOWN")
    map(layer_0, layer_1, "KC_E", "MACRO_NEXT_ERROR")
    map(layer_0, layer_1, "KC_ESC", "MACRO_WIN_JUMP")
    map(layer_0, layer_1, "KC_F1", "MACRO_WIN_1")
    map(layer_0, layer_1, "KC_F2", "MACRO_WIN_2")
    map(layer_0, layer_1, "KC_F3", "MACRO_WIN_3")
    map(layer_0, layer_1, "KC_F4", "MACRO_WIN_4")
    map(layer_0, layer_1, "KC_F9", "MACRO_CTL_ALT_DEL")
    map(layer_0, layer_1, "KC_G", "MACRO_MAGIT")
    map(layer_0, layer_1, "KC_GRV", "MACRO_BUFFER_0")
    map(layer_0, layer_1, "KC_H", "MACRO_SHIFT_INSERT")
    map(layer_0, layer_1, "KC_J", "MACRO_MAKE_J")
    map(layer_0, layer_1, "KC_L", "MACRO_MAKE_CLEAN")
    map(layer_0, layer_1, "KC_LEFT", "MACRO_TMUX_FOCUS_PREV")
    map(layer_0, layer_1, "KC_M", "MACRO_MAKE")
    map(layer_0, layer_1, "KC_N", "MACRO_TMUX_NEW")
    map(layer_0, layer_1, "KC_O", "MACRO_FILE_OPEN")
    map(layer_0, layer_1, "KC_P", "MACRO_TMUX_SPLIT_H")
    map(layer_0, layer_1, "KC_R", "MACRO_COMPILE_AGAIN")
    map(layer_0, layer_1, "KC_RIGHT", "MACRO_TMUX_FOCUS_NEXT")
    map(layer_0, layer_1, "KC_S", "MACRO_FILE_SAVE")
    map(layer_0, layer_1, "KC_UP", "MACRO_TMUX_FOCUS_UP")

    # update layer 0
    #map(layer_0, layer_0, "KC_CAPS", "LT(EMACSTKL_LAYER_1,KC_CAPS)")
    map(layer_0, layer_0, "KC_CAPS", "OSL(EMACSTKL_LAYER_1)")
    # debug l2/3 leds
    map(layer_0, layer_0, "KC_LGUI", "OSL(EMACSTKL_LAYER_2)")
    map(layer_0, layer_0, "KC_F20", "OSL(EMACSTKL_LAYER_3)")
    # rgui further then lgui, swap
    map(layer_0, layer_0, "KC_RGUI", "KC_LGUI")
    # original l-gui is a layer switcher
    #map(layer_0, layer_0, "KC_LGUI", "KC_RGUI")

    # write needed defines
    define_layer("EMACSTKL_INFO_0", layer_0)
    define_layer("EMACSTKL_INFO_1", layer_1)
    define_layer("EMACSTKL_INFO_2", layer_2)
    define_layer("EMACSTKL_INFO_3", layer_3)
    #
    print_map(layer_0, layer_1)

    exit
}
