static const opus_val16 window_16K_320[40] = {
    20, 178, 494, 966, 1590, 2362, 3276, 4325, 5499, 6788,
    8179, 9657, 11207, 12810, 14447, 16098, 17744, 19363, 20936, 22445,
    23874, 25208, 26435, 27548, 28541, 29411, 30160, 30792, 31313, 31731,
    32057, 32303, 32481, 32604, 32683, 32729, 32754, 32764, 32767, 32767,
};

static const opus_val16 logN_16K_320[21] = {
    0, 0, 0, 0, 0, 0, 0, 0, 8, 8,
    8, 8, 16, 16, 16, 21, 21, 24, 29, 34,
    36,
};

static const opus_val16 cache_index_16K_320[105] = {
    -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
    0, 0, 41, 41, 41, 82, 82, 123, 164, 200,
    222, 0, 0, 0, 0, 0, 0, 0, 0, 41,
    41, 41, 41, 123, 123, 123, 164, 164, 240, 266,
    283, 295, 41, 41, 41, 41, 41, 41, 41, 41,
    123, 123, 123, 123, 240, 240, 240, 266, 266, 305,
    318, 328, 336, 123, 123, 123, 123, 123, 123, 123,
    123, 240, 240, 240, 240, 305, 305, 305, 318, 318,
    343, 351, 358, 364, 240, 240, 240, 240, 240, 240,
    240, 240, 305, 305, 305, 305, 343, 343, 343, 351,
    351, 370, 376, 382, 387,
};

static const unsigned char cache_bits_16K_320[392] = {
    40, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 40, 15, 23, 28, 31, 34, 36, 38, 39,
    41, 42, 43, 44, 45, 46, 47, 47, 49, 50,
    51, 52, 53, 54, 55, 55, 57, 58, 59, 60,
    61, 62, 63, 63, 65, 66, 67, 68, 69, 70,
    71, 71, 40, 20, 33, 41, 48, 53, 57, 61,
    64, 66, 69, 71, 73, 75, 76, 78, 80, 82,
    85, 87, 89, 91, 92, 94, 96, 98, 101, 103,
    105, 107, 108, 110, 112, 114, 117, 119, 121, 123,
    124, 126, 128, 40, 23, 39, 51, 60, 67, 73,
    79, 83, 87, 91, 94, 97, 100, 102, 105, 107,
    111, 115, 118, 121, 124, 126, 129, 131, 135, 139,
    142, 145, 148, 150, 153, 155, 159, 163, 166, 169,
    172, 174, 177, 179, 35, 28, 49, 65, 78, 89,
    99, 107, 114, 120, 126, 132, 136, 141, 145, 149,
    153, 159, 165, 171, 176, 180, 185, 189, 192, 199,
    205, 211, 216, 220, 225, 229, 232, 239, 245, 251,
    21, 33, 58, 79, 97, 112, 125, 137, 148, 157,
    166, 174, 182, 189, 195, 201, 207, 217, 227, 235,
    243, 251, 17, 35, 63, 86, 106, 123, 139, 152,
    165, 177, 187, 197, 206, 214, 222, 230, 237, 250,
    25, 31, 55, 75, 91, 105, 117, 128, 138, 146,
    154, 161, 168, 174, 180, 185, 190, 200, 208, 215,
    222, 229, 235, 240, 245, 255, 16, 36, 65, 89,
    110, 128, 144, 159, 173, 185, 196, 207, 217, 226,
    234, 242, 250, 11, 41, 74, 103, 128, 151, 172,
    191, 209, 225, 241, 255, 9, 43, 79, 110, 138,
    163, 186, 207, 227, 246, 12, 39, 71, 99, 123,
    144, 164, 182, 198, 214, 228, 241, 253, 9, 44,
    81, 113, 142, 168, 192, 214, 235, 255, 7, 49,
    90, 127, 160, 191, 220, 247, 6, 51, 95, 134,
    170, 203, 234, 7, 47, 87, 123, 155, 184, 212,
    237, 6, 52, 97, 137, 174, 208, 240, 5, 57,
    106, 151, 192, 231, 5, 59, 111, 158, 202, 243,
    5, 55, 103, 147, 187, 224, 5, 60, 113, 161,
    206, 248, 4, 65, 122, 175, 224, 4, 67, 127,
    182, 234,
};

static const unsigned char cach_caps_16K_320[168] = {
    224, 224, 224, 224, 224, 224, 224, 224, 160, 160,
    160, 160, 185, 185, 185, 178, 178, 168, 134, 61,
    37, 224, 224, 224, 224, 224, 224, 224, 224, 240,
    240, 240, 240, 207, 207, 207, 198, 198, 183, 144,
    66, 40, 160, 160, 160, 160, 160, 160, 160, 160,
    185, 185, 185, 185, 193, 193, 193, 183, 183, 172,
    138, 64, 38, 240, 240, 240, 240, 240, 240, 240,
    240, 207, 207, 207, 207, 204, 204, 204, 193, 193,
    180, 143, 66, 40, 185, 185, 185, 185, 185, 185,
    185, 185, 193, 193, 193, 193, 193, 193, 193, 183,
    183, 172, 138, 65, 39, 207, 207, 207, 207, 207,
    207, 207, 207, 204, 204, 204, 204, 201, 201, 201,
    188, 188, 176, 141, 66, 40, 193, 193, 193, 193,
    193, 193, 193, 193, 193, 193, 193, 193, 194, 194,
    194, 184, 184, 173, 139, 65, 39, 204, 204, 204,
    204, 204, 204, 204, 204, 201, 201, 201, 201, 198,
    198, 198, 187, 187, 175, 140, 66, 40,
};

static const kiss_twiddle_cpx fft_twiddles_16K_320[160] = {
    {32767, 0}, {32743, -1287}, {32667, -2570}, {32541, -3851}, {32364, -5125},
    {32138, -6393}, {31863, -7650}, {31539, -8895}, {31165, -10126}, {30743, -11340},
    {30274, -12540}, {29758, -13718}, {29197, -14875}, {28590, -16010}, {27940, -17119},
    {27246, -18205}, {26510, -19260}, {25734, -20286}, {24918, -21281}, {24063, -22242},
    {23171, -23171}, {22244, -24063}, {21282, -24917}, {20288, -25733}, {19261, -26509},
    {18205, -27246}, {17122, -27940}, {16012, -28590}, {14878, -29197}, {13720, -29757},
    {12540, -30274}, {11342, -30743}, {10127, -31164}, {8895, -31537}, {7650, -31862},
    {6393, -32138}, {5127, -32364}, {3852, -32541}, {2572, -32667}, {1287, -32742},
    {0, -32767}, {-1287, -32743}, {-2570, -32667}, {-3851, -32541}, {-5125, -32364},
    {-6393, -32138}, {-7650, -31863}, {-8895, -31539}, {-10126, -31165}, {-11340, -30743},
    {-12540, -30274}, {-13718, -29758}, {-14875, -29197}, {-16010, -28590}, {-17119, -27940},
    {-18205, -27246}, {-19260, -26510}, {-20286, -25734}, {-21281, -24918}, {-22242, -24063},
    {-23171, -23171}, {-24063, -22244}, {-24917, -21282}, {-25733, -20288}, {-26509, -19261},
    {-27246, -18205}, {-27940, -17122}, {-28590, -16012}, {-29197, -14878}, {-29757, -13720},
    {-30274, -12540}, {-30743, -11342}, {-31164, -10127}, {-31537, -8895}, {-31862, -7650},
    {-32138, -6393}, {-32364, -5127}, {-32541, -3852}, {-32667, -2572}, {-32742, -1287},
    {-32767, 0}, {-32743, 1287}, {-32667, 2570}, {-32541, 3851}, {-32364, 5125},
    {-32138, 6393}, {-31863, 7650}, {-31539, 8895}, {-31165, 10126}, {-30743, 11340},
    {-30274, 12540}, {-29758, 13718}, {-29197, 14875}, {-28590, 16010}, {-27940, 17119},
    {-27246, 18205}, {-26510, 19260}, {-25734, 20286}, {-24918, 21281}, {-24063, 22242},
    {-23171, 23171}, {-22244, 24063}, {-21282, 24917}, {-20288, 25733}, {-19261, 26509},
    {-18205, 27246}, {-17122, 27940}, {-16012, 28590}, {-14878, 29197}, {-13720, 29757},
    {-12540, 30274}, {-11342, 30743}, {-10127, 31164}, {-8895, 31537}, {-7650, 31862},
    {-6393, 32138}, {-5127, 32364}, {-3852, 32541}, {-2572, 32667}, {-1287, 32742},
    {0, 32767}, {1287, 32743}, {2570, 32667}, {3851, 32541}, {5125, 32364},
    {6393, 32138}, {7650, 31863}, {8895, 31539}, {10126, 31165}, {11340, 30743},
    {12540, 30274}, {13718, 29758}, {14875, 29197}, {16010, 28590}, {17119, 27940},
    {18205, 27246}, {19260, 26510}, {20286, 25734}, {21281, 24918}, {22242, 24063},
    {23171, 23171}, {24063, 22244}, {24917, 21282}, {25733, 20288}, {26509, 19261},
    {27246, 18205}, {27940, 17122}, {28590, 16012}, {29197, 14878}, {29757, 13720},
    {30274, 12540}, {30743, 11342}, {31164, 10127}, {31537, 8895}, {31862, 7650},
    {32138, 6393}, {32364, 5127}, {32541, 3852}, {32667, 2572}, {32742, 1287},
};

static const opus_val16 fft_bitrev0_16K_320[160] = {
    0, 32, 64, 96, 128, 8, 40, 72, 104, 136,
    16, 48, 80, 112, 144, 24, 56, 88, 120, 152,
    4, 36, 68, 100, 132, 12, 44, 76, 108, 140,
    20, 52, 84, 116, 148, 28, 60, 92, 124, 156,
    1, 33, 65, 97, 129, 9, 41, 73, 105, 137,
    17, 49, 81, 113, 145, 25, 57, 89, 121, 153,
    5, 37, 69, 101, 133, 13, 45, 77, 109, 141,
    21, 53, 85, 117, 149, 29, 61, 93, 125, 157,
    2, 34, 66, 98, 130, 10, 42, 74, 106, 138,
    18, 50, 82, 114, 146, 26, 58, 90, 122, 154,
    6, 38, 70, 102, 134, 14, 46, 78, 110, 142,
    22, 54, 86, 118, 150, 30, 62, 94, 126, 158,
    3, 35, 67, 99, 131, 11, 43, 75, 107, 139,
    19, 51, 83, 115, 147, 27, 59, 91, 123, 155,
    7, 39, 71, 103, 135, 15, 47, 79, 111, 143,
    23, 55, 87, 119, 151, 31, 63, 95, 127, 159,
};

static const opus_val16 fft_bitrev1_16K_320[80] = {
    0, 16, 32, 48, 64, 4, 20, 36, 52, 68,
    8, 24, 40, 56, 72, 12, 28, 44, 60, 76,
    1, 17, 33, 49, 65, 5, 21, 37, 53, 69,
    9, 25, 41, 57, 73, 13, 29, 45, 61, 77,
    2, 18, 34, 50, 66, 6, 22, 38, 54, 70,
    10, 26, 42, 58, 74, 14, 30, 46, 62, 78,
    3, 19, 35, 51, 67, 7, 23, 39, 55, 71,
    11, 27, 43, 59, 75, 15, 31, 47, 63, 79,
};

static const opus_val16 fft_bitrev2_16K_320[40] = {
    0, 8, 16, 24, 32, 4, 12, 20, 28, 36,
    1, 9, 17, 25, 33, 5, 13, 21, 29, 37,
    2, 10, 18, 26, 34, 6, 14, 22, 30, 38,
    3, 11, 19, 27, 35, 7, 15, 23, 31, 39,
};

static const opus_val16 fft_bitrev3_16K_320[20] = {
    0, 4, 8, 12, 16, 1, 5, 9, 13, 17,
    2, 6, 10, 14, 18, 3, 7, 11, 15, 19,
};

static const opus_val16 mdct_tw_16K_320[600] = {
    32767, 32766, 32761, 32752, 32741, 32726, 32709, 32688, 32663, 32636,
    32607, 32573, 32536, 32496, 32454, 32407, 32358, 32307, 32250, 32192,
    32130, 32066, 31998, 31927, 31853, 31776, 31697, 31613, 31526, 31438,
    31345, 31250, 31152, 31050, 30946, 30839, 30729, 30616, 30499, 30381,
    30258, 30133, 30006, 29875, 29742, 29604, 29466, 29324, 29178, 29031,
    28880, 28728, 28570, 28411, 28250, 28085, 27919, 27749, 27576, 27401,
    27223, 27044, 26861, 26674, 26486, 26296, 26104, 25907, 25708, 25508,
    25304, 25099, 24892, 24680, 24468, 24253, 24036, 23815, 23593, 23369,
    23142, 22913, 22682, 22449, 22213, 21975, 21737, 21495, 21250, 21004,
    20757, 20508, 20255, 20001, 19745, 19487, 19228, 18967, 18703, 18438,
    18171, 17903, 17632, 17360, 17087, 16811, 16536, 16256, 15975, 15694,
    15411, 15127, 14841, 14552, 14263, 13974, 13683, 13390, 13095, 12800,
    12502, 12205, 11906, 11605, 11304, 11000, 10698, 10394, 10088, 9781,
    9473, 9167, 8856, 8545, 8234, 7923, 7611, 7298, 6983, 6669,
    6353, 6038, 5722, 5404, 5086, 4768, 4451, 4132, 3811, 3493,
    3172, 2853, 2531, 2210, 1889, 1568, 1247, 925, 603, 282,
    -41, -361, -684, -1005, -1327, -1648, -1969, -2291, -2611, -2932,
    -3254, -3572, -3891, -4210, -4531, -4849, -5166, -5484, -5800, -6117,
    -6433, -6747, -7061, -7375, -7690, -8002, -8313, -8623, -8933, -9243,
    -9551, -9857, -10164, -10469, -10774, -11078, -11379, -11680, -11980, -12280,
    -12578, -12872, -13169, -13462, -13756, -14047, -14336, -14625, -14912, -15198,
    -15483, -15765, -16045, -16326, -16604, -16881, -17155, -17428, -17700, -17970,
    -18238, -18505, -18769, -19032, -19293, -19553, -19809, -20065, -20318, -20570,
    -20819, -21066, -21312, -21555, -21797, -22036, -22272, -22507, -22740, -22971,
    -23200, -23424, -23649, -23870, -24090, -24307, -24521, -24733, -24943, -25151,
    -25357, -25558, -25758, -25956, -26152, -26344, -26533, -26722, -26906, -27089,
    -27268, -27445, -27619, -27791, -27961, -28128, -28291, -28451, -28609, -28765,
    -28918, -29068, -29215, -29359, -29501, -29640, -29775, -29908, -30037, -30166,
    -30290, -30410, -30529, -30644, -30757, -30866, -30973, -31077, -31176, -31275,
    -31369, -31461, -31548, -31634, -31717, -31796, -31872, -31945, -32015, -32082,
    -32146, -32207, -32265, -32319, -32370, -32420, -32465, -32507, -32545, -32582,
    -32614, -32643, -32671, -32693, -32714, -32731, -32745, -32754, -32762, -32767,
    32767, 32761, 32740, 32706, 32661, 32603, 32531, 32448, 32352, 32244,
    32123, 31989, 31844, 31686, 31515, 31334, 31140, 30934, 30715, 30485,
    30243, 29990, 29725, 29448, 29160, 28861, 28550, 28230, 27898, 27555,
    27202, 26837, 26463, 26078, 25683, 25279, 24865, 24442, 24008, 23565,
    23114, 22654, 22185, 21706, 21220, 20727, 20223, 19714, 19195, 18670,
    18138, 17598, 17053, 16500, 15940, 15376, 14805, 14229, 13646, 13057,
    12465, 11868, 11267, 10660, 10049, 9435, 8817, 8197, 7572, 6944,
    6315, 5681, 5047, 4411, 3771, 3132, 2490, 1850, 1206, 562,
    -80, -725, -1366, -2010, -2653, -3292, -3932, -4569, -5206, -5841,
    -6471, -7101, -7727, -8352, -8973, -9589, -10203, -10812, -11417, -12019,
    -12613, -13206, -13791, -14373, -14949, -15517, -16081, -16638, -17190, -17735,
    -18272, -18803, -19325, -19842, -20350, -20850, -21343, -21826, -22302, -22770,
    -23228, -23678, -24117, -24548, -24970, -25382, -25784, -26175, -26557, -26930,
    -27290, -27641, -27981, -28311, -28629, -28937, -29234, -29519, -29792, -30054,
    -30304, -30544, -30771, -30986, -31190, -31380, -31559, -31726, -31881, -32025,
    -32154, -32272, -32377, -32470, -32550, -32618, -32673, -32716, -32746, -32763,
    32767, 32736, 32653, 32522, 32340, 32107, 31825, 31493, 31114, 30687,
    30213, 29690, 29123, 28511, 27855, 27157, 26415, 25634, 24813, 23953,
    23058, 22124, 21158, 20160, 19131, 18071, 16984, 15870, 14733, 13573,
    12392, 11190, 9972, 8740, 7493, 6236, 4967, 3693, 2410, 1126,
    -160, -1449, -2732, -4012, -5285, -6550, -7807, -9049, -10278, -11492,
    -12688, -13865, -15020, -16151, -17258, -18338, -19392, -20413, -21403, -22360,
    -23284, -24172, -25021, -25833, -26605, -27335, -28024, -28668, -29270, -29825,
    -30335, -30798, -31214, -31581, -31900, -32169, -32390, -32560, -32679, -32748,
    32767, 32640, 32313, 31786, 31063, 30149, 29050, 27770, 26320, 24707,
    22942, 21035, 18999, 16846, 14589, 12241, 9820, 7336, 4809, 2251,
    -322, -2891, -5445, -7962, -10431, -12836, -15162, -17395, -19520, -21524,
    -23398, -25125, -26698, -28106, -29341, -30396, -31262, -31936, -32413, -32690,
};

static const kiss_fft_state fft_state0_16K_320 = {
160,    /* nfft */
26214,    /* scale */
7,    /* scale_shift */
-1,    /* shift */
{5, 32, 4, 8, 2, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, },    /* factors */
fft_bitrev0_16K_320,	/* bitrev */
fft_twiddles_16K_320,	/* twiddles */
NULL,
};

static const kiss_fft_state fft_state1_16K_320 = {
80,    /* nfft */
26214,    /* scale */
6,    /* scale_shift */
1,    /* shift */
{5, 16, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },    /* factors */
fft_bitrev1_16K_320,	/* bitrev */
fft_twiddles_16K_320,	/* twiddles */
NULL,
};

static const kiss_fft_state fft_state2_16K_320 = {
40,    /* nfft */
26214,    /* scale */
5,    /* scale_shift */
2,    /* shift */
{5, 8, 2, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },    /* factors */
fft_bitrev2_16K_320,	/* bitrev */
fft_twiddles_16K_320,	/* twiddles */
NULL,
};

static const kiss_fft_state fft_state3_16K_320 = {
20,    /* nfft */
26214,    /* scale */
4,    /* scale_shift */
3,    /* shift */
{5, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },    /* factors */
fft_bitrev3_16K_320,	/* bitrev */
fft_twiddles_16K_320,	/* twiddles */
NULL,
};

static const CELTMode mode16000_320_40 = {
16000,    /* Fs */
40,    /* overlap */
21,    /* nbEBands */
17,    /* effEBands */
{19661, -5898, 1812, 18513, },    /* preemph */
eband5ms,	/* eBands */
3,    /* maxLM */
8,    /* nbShortMdcts */
40,    /* shortMdctSize */
11,    /* nbAllocVectors */
band_allocation,	/* allocVectors */
logN_16K_320,	/* logN */
window_16K_320,	/* window */
{640, 3, {&fft_state0_16K_320, &fft_state1_16K_320, &fft_state2_16K_320, &fft_state3_16K_320, }, mdct_tw_16K_320},    /* mdct */
{392, cache_index_16K_320, cache_bits_16K_320, cach_caps_16K_320},	/* cache */
};

