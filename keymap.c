#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "custom.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER, 
    _RAISE, 
    _TILDE,
    _NUMBER,
    _MULTIMEDIA,
};

enum {    
    TD_ESCQ,
    TD_RENAME,
    TD_ORG_IMPORTS,
    TD_GENERATE,
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESCQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_RENAME] = ACTION_TAP_DANCE_DOUBLE(KC_R, LSFT(KC_F6)),
    [TD_ORG_IMPORTS] = ACTION_TAP_DANCE_DOUBLE(KC_O, LALT(LCTL(KC_O))),
    [TD_GENERATE] = ACTION_TAP_DANCE_DOUBLE(KC_G, LGUI(KC_N)),
};

#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen 
#define KC_CPYW LGUI(LSFT(LCTL(KC_3))) // Copy whole screen 
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen   
#define KC_CPYP LGUI(LSFT(LCTL(KC_4))) // Copy portion of screen

#define TD_Q_ESC TD(TD_ESCQ)

#define KC_RENAME LSFT(KC_F6)
#define KC_IMPORTS LALT(LCTL(KC_O))
#define KC_GENERATE LGUI(KC_N)
#define KC_COMPILE LGUI(KC_F9)
#define KC_SEARCH LSG(KC_R)
#define KC_OPEN LGUI(KC_O)

#define TTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  

[_QWERTY] = LAYOUT( 
    TD_Q_ESC, KC_W, KC_E, KC_R, LT(_MULTIMEDIA,KC_T),                       KC_Y, KC_U, KC_I, KC_O, KC_P,   
    LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,           KC_H , RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), LCTL_T(KC_BSPC),   
    KC_Z, KC_X, KC_C, LT(_TILDE,KC_V), KC_B,                                KC_N ,LT(_NUMBER,KC_M), KC_COMM, KC_DOT, KC_SLSH,    
                                   KC_TAB , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT), OSM(MOD_RGUI)),

[_NUMBER] = LAYOUT(    
    KC_1, KC_2, KC_3, KC_4, KC_5,                                           TTT, TTT, TTT, TTT, TTT,    
    KC_6, KC_7, KC_8, KC_9, KC_0,                                           TTT, TTT,  TTT, TTT, TTT,    
    ES_PLUS, ES_MINS, KC_COMM, KC_DOT, ES_EQL,                              TTT, TTT, TTT, TTT, TTT,     
                                        TTT, TTT, TTT, TTT),
    
[_LOWER] = LAYOUT(    
    ES_HASH, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,    
    ES_AMPR, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,    
    ES_AT, ES_LBRC, ES_RBRC, ES_ASTR, ES_EQL,                               KC_F11, KC_F12, KC_CAPP, KC_CPYP , TTT,    
                                       ES_PIPE, ES_PERC, TTT, TTT),

[_RAISE] = LAYOUT(    
     TTT, KC_GENERATE, KC_IMPORTS, KC_RENAME, KC_DEL,                       TTT, KC_PGDN, KC_PGUP, KC_HOME, KC_END,    
     TTT, KC_SEARCH, KC_OPEN, KC_COMPILE, KC_CAPS,                          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS,    
     TTT, TTT, TTT, TTT, TTT,                                               TTT, KC_RSFT, ES_SCLN, ES_COLN, LCTL_T(ES_UNDS),    
                                       TTT, TTT, KC_PSCR, TTT),

  [_TILDE] = LAYOUT( 
   TTT, TTT, TTT, TTT, TTT,                                                ES_CIRC, ES_TILD, ES_DLR, ES_IQUE, ES_QUES,
   TTT, TTT, TTT, TTT, TTT,                                                ES_GRV, ES_ACUT , ES_QUOT, ES_DQUO, TTT, 
   TTT, TTT, TTT, TTT, TTT,                                                KC_SCLN, ES_IEXL, ES_EXLM, TTT, TTT, 
                             TTT,  TTT, TTT, TTT ),

  [_MULTIMEDIA] = LAYOUT( 
   TTT, TTT, TTT, TTT, TTT,                                                TTT, TTT, TTT, TTT, TTT,
   TTT, TTT, TTT, TTT, TTT,                                                TTT, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, TTT, TTT,
   TTT, TTT, TTT, TTT, TTT,                                                TTT, KC_KB_MUTE, TTT, TTT, TTT,
                             TTT,  TTT, TTT, TTT ),

};


