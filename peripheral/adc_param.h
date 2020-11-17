/*********************************************************************
* @file
* adc_param.h
*
* @brief
* adc look up table definition
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef ADC_PARAM_H
#define ADC_PARAM_H

#ifdef __cplusplus
extern "C"{
#endif


/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "board.h"

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    float              adc_vol;
    int16_t            adc_temp;
    } adc_param_type;

typedef struct
    {
    float              adc_vol_exact;
    uint8_t            pcb_ver;
    } adc_param_pcb_ver_type;

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
static const adc_param_type adc_vol2temperature_pcb[]=
    {
    { 1.712473499 , -40 },
    { 1.707653048 , -39 },
    { 1.70262122  , -38 },
    { 1.697372157 , -37 },
    { 1.691900008 , -36 },
    { 1.686199114 , -35 },
    { 1.680263739 , -34 },
    { 1.674088541 , -33 },
    { 1.667667979 , -32 },
    { 1.660996991 , -31 },
    { 1.654070343 , -30 },
    { 1.646893078 , -29 },
    { 1.63945128  , -28 },
    { 1.631740477 , -27 },
    { 1.623756627 , -26 },
    { 1.615495886 , -25 },
    { 1.606954776 , -24 },
    { 1.598130011 , -23 },
    { 1.589018903 , -22 },
    { 1.579619182 , -21 },
    { 1.569928946 , -20 },
    { 1.559970236 , -19 },
    { 1.549718433 , -18 },
    { 1.53917315  , -17 },
    { 1.528334282 , -16 },
    { 1.517201679 , -15 },
    { 1.505776105 , -14 },
    { 1.494059138 , -13 },
    { 1.482052949 , -12 },
    { 1.469759915 , -11 },
    { 1.457183342 , -10 },
    { 1.444266666 , -9 },
    { 1.431075722 , -8 },
    { 1.417614381 , -7 },
    { 1.403888059 , -6 },
    { 1.389904357 , -5 },
    { 1.375668852 , -4 },
    { 1.361189664 , -3 },
    { 1.346473834 , -2 },
    { 1.331531813 , -1 },
    { 1.316370847 , 0 },
    { 1.301053332 , 1 },
    { 1.285533487 , 2 },
    { 1.269822597 , 3 },
    { 1.253931541 , 4 },
    { 1.237870654 , 5 },
    { 1.221649584 , 6 },
    { 1.205285034 , 7 },
    { 1.18878419  , 8 },
    { 1.172161647 , 9 },
    { 1.155427835 , 10 },
    { 1.138573303 , 11 },
    { 1.121635311 , 12 },
    { 1.104632692 , 13 },
    { 1.087574508 , 14 },
    { 1.070472369 , 15 },
    { 1.053344395 , 16 },
    { 1.036200693 , 17 },
    { 1.019051668 , 18 },
    { 1.001915403 , 19 },
    { 0.984801069 , 20 },
    { 0.967749363 , 21 },
    { 0.950731079 , 22 },
    { 0.93376164  , 23 },
    { 0.91684616  , 24 },
    { 0.9         , 25 },
    { 0.883232319 , 26 },
    { 0.866559494 , 27 },
    { 0.849981527 , 28 },
    { 0.833515534 , 29 },
    { 0.817172186 , 30 },
    { 0.801004545 , 31 },
    { 0.784983393 , 32 },
    { 0.769125303 , 33 },
    { 0.75343361  , 34 },
    { 0.737921512 , 35 },
    { 0.722587944 , 36 },
    { 0.70744214  , 37 },
    { 0.692484895 , 38 },
    { 0.67773552  , 39 },
    { 0.663177041 , 40 },
    { 0.64878835  , 41 },
    { 0.634604478 , 42 },
    { 0.620623366 , 43 },
    { 0.606864506 , 44 },
    { 0.593314965 , 45 },
    { 0.579983598 , 46 },
    { 0.566878353 , 47 },
    { 0.553988966 , 48 },
    { 0.541329156 , 49 },
    { 0.52889435  , 50 },
    { 0.516687342 , 51 },
    { 0.504700498 , 52 },
    { 0.492943346 , 53 },
    { 0.481415281 , 54 },
    { 0.470114518 , 55 },
    { 0.459028093 , 56 },
    { 0.4481615   , 57 },
    { 0.437529993 , 58 },
    { 0.427107009 , 59 },
    { 0.416906019 , 60 },
    { 0.407069894 , 61 },
    { 0.39744267  , 62 },
    { 0.388035958 , 63 },
    { 0.378838911 , 64 },
    { 0.369850867 , 65 },
    { 0.361070564 , 66 },
    { 0.3524845   , 67 },
    { 0.344101589 , 68 },
    { 0.335906884 , 69 },
    { 0.327908403 , 70 },
    { 0.320065446 , 71 },
    { 0.312408988 , 72 },
    { 0.304933719 , 73 },
    { 0.297633773 , 74 },
    { 0.290502746 , 75 },
    { 0.283546479 , 76 },
    { 0.276770754 , 77 },
    { 0.270142277 , 78 },
    { 0.263691919 , 79 },
    { 0.257385268 , 80 },
    { 0.25126652  , 81 },
    { 0.24528706  , 82 },
    { 0.239464216 , 83 },
    { 0.233788405 , 84 },
    { 0.228235869 , 85 },
    { 0.222837316 , 86 },
    { 0.217568506 , 87 },
    { 0.212432418 , 88 },
    { 0.207431984 , 89 },
    { 0.202555911 , 90 },
    { 0.197763991 , 91 },
    { 0.193086702 , 92 },
    { 0.188540734 , 93 },
    { 0.184099539 , 94 },
    { 0.17977965  , 95 },
    { 0.175553891 , 96 },
    { 0.171453387 , 97 },
    { 0.167435786 , 98 },
    { 0.163532225 , 99 },
    { 0.159729538 , 100 },
    { 0.156044277 , 101 },
    { 0.152463068 , 102 },
    { 0.148957091 , 103 },
    { 0.145557823 , 104 },
    { 0.142236139 , 105 },
    { 0.138993061 , 106 },
    { 0.135829589 , 107 },
    { 0.13276215  , 108 },
    { 0.129760877 , 109 },
    { 0.126826548 , 110 },
    { 0.12397553  , 111 },
    { 0.121193072 , 112 },
    { 0.118479906 , 113 },
    { 0.115836748 , 114 },
    { 0.113264302 , 115 },
    { 0.1107474   , 116 },
    { 0.108302476 , 117 },
    { 0.105914242 , 118 },
    { 0.103583209 , 119 },
    { 0.101309879 , 120 },
    { 0.09909474  , 121 },
    { 0.096938273 , 122 },
    { 0.094840947 , 123 },
    { 0.092787025 , 124 },
    { 0.090776842 , 125 },
    { 0.088826991 , 126 },
    { 0.086921598 , 127 },
    { 0.085077314 , 128 },
    { 0.083261803 , 129 },
    { 0.081491665 , 130 },
    { 0.079767195 , 131 },
    { 0.078088678 , 132 },
    { 0.076439891 , 133 },
    { 0.074837547 , 134 },
    { 0.073265351 , 135 },
    { 0.07174007  , 136 },
    { 0.070261959 , 137 },
    { 0.068797969 , 138 },
    { 0.067381532 , 139 },
    { 0.066012889 , 140 },
    { 0.064658813 , 141 },
    { 0.063336131 , 142 },
    { 0.062061774 , 143 },
    { 0.06080235  , 144 },
    { 0.059574756 , 145 },
    { 0.058379132 , 146 },
    { 0.057215611 , 147 },
    { 0.056067432 , 148 },
    { 0.054968492 , 149 },
    { 0.053868167 , 150 }
    };

static const adc_param_type adc_vol2temperature_tft[]=
    {
    { 1.560693457 , -40 },
    { 1.548740328 , -39 },
    { 1.536386305 , -38 },
    { 1.523631078 , -37 },
    { 1.510475169 , -36 },
    { 1.496920374 , -35 },
    { 1.4829691   , -34 },
    { 1.468625458 , -33 },
    { 1.453893854 , -32 },
    { 1.438780523 , -31 },
    { 1.423291995 , -30 },
    { 1.407458007 , -29 },
    { 1.391266733 , -28 },
    { 1.374728141 , -27 },
    { 1.357853625 , -26 },
    { 1.3406554   , -25 },
    { 1.323146807 , -24 },
    { 1.30534185  , -23 },
    { 1.287255936 , -22 },
    { 1.268905394 , -21 },
    { 1.250307268 , -20 },
    { 1.231523296 , -19 },
    { 1.212526246 , -18 },
    { 1.193335453 , -17 },
    { 1.173970384 , -16 },
    { 1.154449991 , -15 },
    { 1.134794322 , -14 },
    { 1.115024183 , -13 },
    { 1.095160625 , -12 },
    { 1.075224211 , -11 },
    { 1.055236104 , -10 },
    { 1.035124229 , -9 },
    { 1.015007886 , -8 },
    { 0.994905841 , -7 },
    { 0.974838062 , -6 },
    { 0.954826411 , -5 },
    { 0.934888505 , -4 },
    { 0.915044248 , -3 },
    { 0.895310694 , -2 },
    { 0.875708068 , -1 },
    { 0.856250939 , 0 },
    { 0.837021186 , 1 },
    { 0.817962199 , 2 },
    { 0.799089913 , 3 },
    { 0.780418368 , 4 },
    { 0.761959666 , 5 },
    { 0.74372396  , 6 },
    { 0.725728018 , 7 },
    { 0.707976825 , 8 },
    { 0.690482394 , 9 },
    { 0.673251192 , 10 },
    { 0.656269022 , 11 },
    { 0.639568147 , 12 },
    { 0.623160207 , 13 },
    { 0.607046379 , 14 },
    { 0.5912297   , 15 },
    { 0.575718415 , 16 },
    { 0.560512689 , 17 },
    { 0.545612548 , 18 },
    { 0.531024111 , 19 },
    { 0.516745286 , 20 },
    { 0.502799311 , 21 },
    { 0.48915176  , 22 },
    { 0.475805245 , 23 },
    { 0.462753984 , 24 },
    { 0.45        , 25 },
    { 0.437540306 , 26 },
    { 0.425377067 , 27 },
    { 0.413500398 , 28 },
    { 0.40191279  , 29 },
    { 0.390611909 , 30 },
    { 0.379623916 , 31 },
    { 0.3689185   , 32 },
    { 0.358496993 , 33 },
    { 0.348351976 , 34 },
    { 0.338482566 , 35 },
    { 0.328878924 , 36 },
    { 0.319537986 , 37 },
    { 0.310451664 , 38 },
    { 0.301623241 , 39 },
    { 0.29303447  , 40 },
    { 0.284665658 , 41 },
    { 0.2765301   , 42 },
    { 0.26861946  , 43 },
    { 0.260937745 , 44 },
    { 0.253470955 , 45 },
    { 0.246217547 , 46 },
    { 0.239175538 , 47 },
    { 0.232333414 , 48 },
    { 0.225692695 , 49 },
    { 0.219245395 , 50 },
    { 0.212987639 , 51 },
    { 0.206910468 , 52 },
    { 0.201013876 , 53 },
    { 0.195292859 , 54 },
    { 0.189742061 , 55 },
    { 0.184350943 , 56 },
    { 0.17911824  , 57 },
    { 0.174047387 , 58 },
    { 0.169122044 , 59 },
    { 0.164345147 , 60 },
    { 0.15977936  , 61 },
    { 0.155348316 , 62 },
    { 0.151054409 , 63 },
    { 0.146889857 , 64 },
    { 0.142851707 , 65 },
    { 0.138936858 , 66 },
    { 0.135136935 , 67 },
    { 0.131453644 , 68 },
    { 0.127878294 , 69 },
    { 0.124412381 , 70 },
    { 0.12103648  , 71 },
    { 0.11776225  , 72 },
    { 0.1145857   , 73 },
    { 0.111502731 , 74 },
    { 0.108509139 , 75 },
    { 0.105605934 , 76 },
    { 0.102794104 , 77 },
    { 0.100058554 , 78 },
    { 0.097410803 , 79 },
    { 0.094835562 , 80 },
    { 0.092349727 , 81 },
    { 0.089932452 , 82 },
    { 0.087589783 , 83 },
    { 0.085316915 , 84 },
    { 0.083103513 , 85 },
    { 0.080961006 , 86 },
    { 0.078878977 , 87 },
    { 0.076857882 , 88 },
    { 0.074898171 , 89 },
    { 0.072994755 , 90 },
    { 0.071131416 , 91 },
    { 0.069319522 , 92 },
    { 0.067564966 , 93 },
    { 0.065856972 , 94 },
    { 0.064201404 , 95 },
    { 0.062587393 , 96 },
    { 0.061026381 , 97 },
    { 0.059501831 , 98 },
    { 0.058025181 , 99 },
    { 0.056591054 , 100 },
    { 0.055205304 , 101 },
    { 0.053862521 , 102 },
    { 0.052551598 , 103 },
    { 0.051284011 , 104 },
    { 0.05004861  , 105 },
    { 0.048845535 , 106 },
    { 0.047674924 , 107 },
    { 0.046542604 , 108 },
    { 0.045437325 , 109 },
    { 0.044359191 , 110 },
    { 0.043314021 , 111 },
    { 0.042296212 , 112 },
    { 0.041305863 , 113 },
    { 0.040343068 , 114 },
    { 0.039407919 , 115 },
    { 0.038494761 , 116 },
    { 0.037609415 , 117 },
    { 0.036746209 , 118 },
    { 0.035905209 , 119 },
    { 0.035086481 , 120 },
    { 0.034290087 , 121 },
    { 0.033516088 , 122 },
    { 0.032764545 , 123 },
    { 0.032029728 , 124 },
    { 0.031311679 , 125 },
    { 0.030616237 , 126 },
    { 0.029937654 , 127 },
    { 0.029281777 , 128 },
    { 0.028637035 , 129 },
    { 0.028009267 , 130 },
    { 0.02739851  , 131 },
    { 0.026804801 , 132 },
    { 0.026222346 , 133 },
    { 0.025657    , 134 },
    { 0.02510296  , 135 },
    { 0.024566087 , 136 },
    { 0.024046412 , 137 },
    { 0.023532276 , 138 },
    { 0.023035385 , 139 },
    { 0.022555767 , 140 },
    { 0.022081745 , 141 },
    { 0.021619183 , 142 },
    { 0.021173959 , 143 },
    { 0.020734375 , 144 },
    { 0.020306305 , 145 },
    { 0.019889765 , 146 },
    { 0.019484772 , 147 },
    { 0.019085467 , 148 },
    { 0.018703612 , 149 },
    { 0.018321593 , 150 },
    };

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif
