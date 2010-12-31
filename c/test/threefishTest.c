#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <threefishApi.h>

static uint64_t three_256_00_key[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L };

static uint64_t three_256_00_input[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L };

static uint64_t three_256_00_tweak[] = { 0L, 0L };

static uint64_t three_256_00_result[] = { 0x94EEEA8B1F2ADA84L, 0xADF103313EAE6670L,
                                        0x952419A1F4B16D53L, 0xD83F13E63C9F6B11L
                                        };

static uint64_t three_256_01_key[] = { 0x1716151413121110L, 0x1F1E1D1C1B1A1918L,
                                       0x2726252423222120L, 0x2F2E2D2C2B2A2928L
                                     };

static uint64_t three_256_01_input[] = { 0xF8F9FAFBFCFDFEFFL, 0xF0F1F2F3F4F5F6F7L,
                                       0xE8E9EAEBECEDEEEFL, 0xE0E1E2E3E4E5E6E7L
                                       };

static uint64_t three_256_01_result[] = { 0x277610F5036C2E1FL, 0x25FB2ADD1267773EL,
                                        0x9E1D67B3E4B06872L, 0x3F76BC7651B39682L
                                        };

static uint64_t three_256_01_tweak[] = { 0x0706050403020100L, 0x0F0E0D0C0B0A0908L };

static uint64_t three_512_00_key[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                       0L, 0L, 0L, 0L
                                     };

static uint64_t three_512_00_input[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                       0L, 0L, 0L, 0L, 0L
                                       };

static uint64_t three_512_00_tweak[] = { 0L, 0L };

static uint64_t three_512_00_result[] = { 0xBC2560EFC6BBA2B1L, 0xE3361F162238EB40L,
                                        0xFB8631EE0ABBD175L, 0x7B9479D4C5479ED1L, 0xCFF0356E58F8C27BL,
                                        0xB1B7B08430F0E7F7L, 0xE9A380A56139ABF1L, 0xBE7B6D4AA11EB47EL
                                        };

static uint64_t three_512_01_key[] = { 0x1716151413121110L, 0x1F1E1D1C1B1A1918L,
                                       0x2726252423222120L, 0x2F2E2D2C2B2A2928L, 0x3736353433323130L,
                                       0x3F3E3D3C3B3A3938L, 0x4746454443424140L, 0x4F4E4D4C4B4A4948L
                                     };

static uint64_t three_512_01_input[] = { 0xF8F9FAFBFCFDFEFFL, 0xF0F1F2F3F4F5F6F7L,
                                       0xE8E9EAEBECEDEEEFL, 0xE0E1E2E3E4E5E6E7L, 0xD8D9DADBDCDDDEDFL,
                                       0xD0D1D2D3D4D5D6D7L, 0xC8C9CACBCCCDCECFL, 0xC0C1C2C3C4C5C6C7L
                                       };

static uint64_t three_512_01_tweak[] = { 0x0706050403020100L, 0x0F0E0D0C0B0A0908L };

static uint64_t three_512_01_result[] = { 0xD4A32EDD6ABEFA1CL, 0x6AD5C4252C3FF743L,
                                        0x35AC875BE2DED68CL, 0x99A6C774EA5CD06CL, 0xDCEC9C4251D7F4F8L,
                                        0xF5761BCB3EF592AFL, 0xFCABCB6A3212DF60L, 0xFD6EDE9FF9A2E14EL
                                        };

static uint64_t three_1024_00_key[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                        0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                        0L, 0L, 0L, 0L
                                      };

static uint64_t three_1024_00_input[] = { 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                        0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L,
                                        0L, 0L, 0L, 0L
                                        };

static uint64_t three_1024_00_tweak[] = { 0L, 0L };

static uint64_t three_1024_00_result[] = { 0x04B3053D0A3D5CF0L, 0x0136E0D1C7DD85F7L,
        0x067B212F6EA78A5CL, 0x0DA9C10B4C54E1C6L, 0x0F4EC27394CBACF0L,
        0x32437F0568EA4FD5L, 0xCFF56D1D7654B49CL, 0xA2D5FB14369B2E7BL,
        0x540306B460472E0BL, 0x71C18254BCEA820DL, 0xC36B4068BEAF32C8L,
        0xFA4329597A360095L, 0xC4A36C28434A5B9AL, 0xD54331444B1046CFL,
        0xDF11834830B2A460L, 0x1E39E8DFE1F7EE4FL
                                         };

static uint64_t three_1024_01_key[] = { 0x1716151413121110L, 0x1F1E1D1C1B1A1918L,
                                        0x2726252423222120L, 0x2F2E2D2C2B2A2928L, 0x3736353433323130L,
                                        0x3F3E3D3C3B3A3938L, 0x4746454443424140L, 0x4F4E4D4C4B4A4948L,
                                        0x5756555453525150L, 0x5F5E5D5C5B5A5958L, 0x6766656463626160L,
                                        0x6F6E6D6C6B6A6968L, 0x7776757473727170L, 0x7F7E7D7C7B7A7978L,
                                        0x8786858483828180L, 0x8F8E8D8C8B8A8988L
                                      };

static uint64_t three_1024_01_input[] = { 0xF8F9FAFBFCFDFEFFL, 0xF0F1F2F3F4F5F6F7L,
                                        0xE8E9EAEBECEDEEEFL, 0xE0E1E2E3E4E5E6E7L, 0xD8D9DADBDCDDDEDFL,
                                        0xD0D1D2D3D4D5D6D7L, 0xC8C9CACBCCCDCECFL, 0xC0C1C2C3C4C5C6C7L,
                                        0xB8B9BABBBCBDBEBFL, 0xB0B1B2B3B4B5B6B7L, 0xA8A9AAABACADAEAFL,
                                        0xA0A1A2A3A4A5A6A7L, 0x98999A9B9C9D9E9FL, 0x9091929394959697L,
                                        0x88898A8B8C8D8E8FL, 0x8081828384858687L
                                        };

static uint64_t three_1024_01_tweak[] = { 0x0706050403020100L, 0x0F0E0D0C0B0A0908L };

static uint64_t three_1024_01_result[] = { 0x483AC62C27B09B59L, 0x4CB85AA9E48221AAL,
        0x80BC1644069F7D0BL, 0xFCB26748FF92B235L, 0xE83D70243B5D294BL,
        0x316A3CA3587A0E02L, 0x5461FD7C8EF6C1B9L, 0x7DD5C1A4C98CA574L,
        0xFDA694875AA31A35L, 0x03D1319C26C2624CL, 0xA2066D0DF2BF7827L,
        0x6831CCDAA5C8A370L, 0x2B8FCD9189698DACL, 0xE47818BBFD604399L,
        0xDF47E519CBCEA541L, 0x5EFD5FF4A5D4C259L
                                         };

static const char INDENT[] =  "    ";
static void Show08(size_t cnt, const uint8_t* b)
{
    size_t i;
    for (i=0;i < cnt;i++)
    {
        if (i %16 ==  0) printf(INDENT);
        else if (i % 4 == 0) printf(" ");
        printf(" %02X",b[i]);
        if (i %16 == 15 || i==cnt-1) printf("\n");
        fflush(stdout);
    }
}

/*
 * ATTENTION: the following tests work for little endian CPU, not tested for
 * big endian :-)
 */
static int basicTest256()
{
    int i;
    ThreefishKey_t keyCtx;
    uint64_t cipher[Threefish256/64];
    uint64_t plain[Threefish256/64];

    /* setup and check first vector */
    threefishSetKey(&keyCtx, Threefish256, three_256_00_key, three_256_00_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_256_00_input, cipher);
    if (memcmp(cipher, three_256_00_result, Threefish256/8) != 0) {
        printf("Wrong cipher text 256 00\n");
        Show08(Threefish256/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_256_00_input, Threefish256/8) != 0) {
        printf("Decrypt failed 256 00\n");
        Show08(Threefish256/8, (const uint8_t*)cipher);
        Show08(Threefish256/8, (const uint8_t*)plain);
        return 0;
    }
    /* setup and check second vector */
    threefishSetKey(&keyCtx, Threefish256, three_256_01_key, three_256_01_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_256_01_input, cipher);

    /* plaintext feed forward */
    for (i = 0; i < Threefish256/64; i++)
        cipher[i] ^= three_256_01_input[i];

    if (memcmp(cipher, three_256_01_result, Threefish256/8) != 0) {
        printf("Wrong cipher text 256 01\n");
        Show08(Threefish256/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    /* plaintext feed backward :-) */
    for (i = 0; i < Threefish256/64; i++)
        cipher[i] ^= three_256_01_input[i];

    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_256_01_input, Threefish256/8) != 0) {
        printf("Decrypt failed 256 01\n");
        Show08(Threefish256/8, (const uint8_t*)plain);
        return 0;
    }
    return 1;
}

static int basicTest512()
{
    int i;
    ThreefishKey_t keyCtx;
    uint64_t cipher[Threefish512/64];
    uint64_t plain[Threefish512/64];

    /* setup and check first vector */
    threefishSetKey(&keyCtx, Threefish512, three_512_00_key, three_512_00_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_512_00_input, cipher);
    if (memcmp(cipher, three_512_00_result, Threefish512/8) != 0) {
        printf("Wrong cipher text 512 00\n");
        Show08(Threefish512/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_512_00_input, Threefish512/8) != 0) {
        printf("Decrypt failed 512 00\n");
        Show08(Threefish512/8, (const uint8_t*)plain);
        return 0;
    }
    /* setup and check second vector */
    threefishSetKey(&keyCtx, Threefish512, three_512_01_key, three_512_01_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_512_01_input, cipher);

    /* plaintext feed forward */
    for (i = 0; i < Threefish512/64; i++)
        cipher[i] ^= three_512_01_input[i];

    if (memcmp(cipher, three_512_01_result, Threefish512/8) != 0) {
        printf("Wrong cipher text 512 01\n");
        Show08(Threefish512/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    /* plaintext feed backward :-) */
    for (i = 0; i < Threefish512/64; i++)
        cipher[i] ^= three_512_01_input[i];

    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_512_01_input, Threefish512/8) != 0) {
        printf("Decrypt failed 512 01\n");
        Show08(Threefish512/8, (const uint8_t*)plain);
        return 0;
    }
    return 1;
}

static int basicTest1024()
{
    int i;
    ThreefishKey_t keyCtx;
    uint64_t cipher[Threefish1024/64];
    uint64_t plain[Threefish1024/64];

    /* setup and check first vector */
    threefishSetKey(&keyCtx, Threefish1024, three_1024_00_key, three_1024_00_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_1024_00_input, cipher);
    if (memcmp(cipher, three_1024_00_result, Threefish1024/8) != 0) {
        printf("Wrong cipher text 1024 00\n");
        Show08(Threefish1024/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_1024_00_input, Threefish1024/8) != 0) {
        printf("Decrypt failed 1024 00\n");
        Show08(Threefish1024/8, (const uint8_t*)plain);
        return 0;
    }
    /* setup and check second vector */
    threefishSetKey(&keyCtx, Threefish1024, three_1024_01_key, three_1024_01_tweak);

    /* Encrypt */
    threefishEncryptBlockWords(&keyCtx, three_1024_01_input, cipher);

    /* plaintext feed forward */
    for (i = 0; i < Threefish1024/64; i++)
        cipher[i] ^= three_1024_01_input[i];

    if (memcmp(cipher, three_1024_01_result, Threefish1024/8) != 0) {
        printf("Wrong cipher text 1024 01\n");
        Show08(Threefish1024/8, (const uint8_t*)cipher);
        return 0;
    }
    /* Decrypt */
    /* plaintext feed backward :-) */
    for (i = 0; i < Threefish1024/64; i++)
        cipher[i] ^= three_1024_01_input[i];

    threefishDecryptBlockWords(&keyCtx, cipher, plain);
    if (memcmp(plain, three_1024_01_input, Threefish1024/8) != 0) {
        printf("Decrypt failed 1024 01\n");
        Show08(Threefish1024/8, (const uint8_t*)plain);
        return 0;
    }
    return 1;
}


int main(int argc, char* argv[])
{
    if (!basicTest256())
        return 1;
    if (!basicTest512())
        return 2;
    if (!basicTest1024())
        return 3;

    return 0;
}
