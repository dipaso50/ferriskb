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
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESCQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC), 
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
#define KC_BACK LGUI(ES_LBRC)
#define KC_NEXT LGUI(ES_RBRC)

#define TTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  

[_QWERTY] = LAYOUT(  
    KC_Q, KC_W, KC_E, KC_R, LT(_MULTIMEDIA,KC_T),                                 KC_Y, KC_U, KC_I, KC_O, KC_P,   
    LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), LT(_TILDE,KC_G),          LT(_NUMBER,KC_H) , RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), LCTL_T(KC_BSPC),   
    KC_Z, KC_X, KC_C, KC_V, KC_B,                                                     KC_N , KC_M, KC_COMM, KC_DOT, KC_SLSH,    
                                   MT(MOD_RGUI, KC_TAB) , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT), OSM(MOD_RGUI)),

[_NUMBER] = LAYOUT(    
    KC_1, KC_2, KC_3, KC_4, KC_5,                                           TTT, TTT, TTT, TTT, TTT,    
    KC_6, KC_7, KC_8, KC_9, KC_0,                                           TTT, TTT,  TTT, TTT, TTT,    
    ES_PLUS, ES_MINS, KC_COMM, KC_DOT, ES_EQL,                              TTT, TTT, TTT, TTT, TTT,     
                                       ES_ASTR, ES_SLSH, TTT, TTT),
    
[_LOWER] = LAYOUT(    
    ES_HASH, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,    
    ES_AMPR, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,    
    ES_AT, ES_LBRC, ES_RBRC, ES_ASTR, ES_EQL,                               KC_F11, KC_F12, KC_CAPP, KC_CPYP , TTT,    
                                       ES_PIPE, ES_PERC, TTT, TTT),

[_RAISE] = LAYOUT(    
     TTT, KC_GENERATE, KC_IMPORTS, KC_RENAME,  KC_DEL,                       KC_HOME, KC_PGDN, KC_PGUP, KC_END, TTT,    
     TTT, TTT        , TTT,        TTT,        KC_ESC,                       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS,    
     TTT, KC_SEARCH  , KC_OPEN,    KC_COMPILE, KC_CAPS,                      TTT, KC_BACK, KC_NEXT, TTT, TTT,    
                                       TTT, TTT, TTT, TTT),

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


