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
    TD_ESCQ
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESCQ] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen 
#define KC_CPYW LGUI(LSFT(LCTL(KC_3))) // Copy whole screen 
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen   
#define KC_CPYP LGUI(LSFT(LCTL(KC_4))) // Copy portion of screen

#define TD_Q_ESC TD(TD_ESCQ)

#define TTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  

[_QWERTY] = LAYOUT( 
    TD_Q_ESC, KC_W, KC_E, KC_R, LT(_MULTIMEDIA,KC_T),                                       KC_Y, KC_U, KC_I, KC_O, KC_P, 
    //----------------------------------                                         -------------------------------------
    KC_A, KC_S, KC_D, LT(_TILDE, KC_F), KC_G,                               KC_H, LT(_NUMBER, KC_J), KC_K, KC_L, KC_BSPC, 
    //----------------------------------                                         ------------------- ------------------
    LCTL_T(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), LSFT_T(KC_V), KC_B,           KC_N , RSFT_T(KC_M), RALT_T(KC_COMM), RGUI_T(KC_DOT), LCTL_T(KC_SLSH),
    //----------------------------------                                     -------------------------------------
                                   KC_TAB , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT), OSM(MOD_RGUI)),



[_NUMBER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    KC_1, KC_2, KC_3, KC_4, KC_5,                                                TTT, TTT, TTT, TTT, TTT, 
    //----------------------------------                                         -------------------------------------
    KC_6, KC_7, KC_8, KC_9, KC_0,                                                TTT, TTT,  TTT, TTT, TTT, 
    //----------------------------------                                         -------------------------------------
    ES_PLUS, ES_MINS, ES_ASTR, ES_SLSH, ES_EQL,                                  TTT, TTT, TTT, TTT, TTT, 
    //----------------------------------                                         -------------------------------------
                                                 TTT, TTT, TTT, TTT),
    //----------------------------------                                         -------------------------------------

[_LOWER] = LAYOUT( 
    //----------------------------------                                         -------------------------------------
    ES_HASH, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, 
    //----------------------------------                                         -------------------------------------
    ES_AMPR, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
    //----------------------------------                                         -------------------------------------
    ES_AT, ES_LBRC, ES_RBRC, ES_ASTR, ES_EQL,                               KC_F11, KC_F12, KC_CAPP, KC_CPYP , TTT, 
    //----------------------------------                                         -------------------------------------
                                       ES_PIPE, ES_PERC, TTT, TTT),

[_RAISE] = LAYOUT( 
    //----------------------------------                                         -------------------------------------
     TTT, TTT, TTT, TTT, KC_DEL,                                                 TTT, KC_PGDN, KC_PGUP, KC_HOME, KC_END, 
    //----------------------------------                                         -------------------------------------  
     TTT, LSG(KC_R), LGUI(KC_O), LGUI(KC_F9), KC_CAPS,                           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS, 
    //----------------------------------                                         -------------------------------------
     TTT, TTT, TTT, TTT, TTT,                                                    TTT, KC_RSFT, ES_SCLN, ES_COLN, LCTL_T(ES_UNDS), 
    //----------------------------------                                         -------------------------------------
                                        TTT, TTT, KC_PSCR, TTT),


  [_TILDE] = LAYOUT( 
   TTT, TTT, TTT, TTT, TTT,                   ES_CIRC, ES_TILD, ES_DIAE, ES_IQUE, ES_QUES,
   TTT, TTT, TTT, TTT, TTT,                   ES_GRV, ES_ACUT , ES_QUOT, ES_DQUO, TTT, 
   TTT, TTT, TTT, TTT, TTT,                   KC_SCLN, ES_IEXL, ES_EXLM, TTT, TTT, 
                             TTT,  TTT, TTT, TTT ),

  [_MULTIMEDIA] = LAYOUT( 
   TTT, TTT, TTT, TTT, TTT,                   TTT, TTT, TTT, TTT, TTT,
   TTT, TTT, TTT, TTT, TTT,                   TTT, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, TTT, TTT,
   TTT, TTT, TTT, TTT, TTT,                   TTT, KC_KB_MUTE, TTT, TTT, TTT,
                             TTT,  TTT, TTT, TTT ),

};


