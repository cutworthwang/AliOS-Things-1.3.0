/**
 * Copyright (C) 2015 The YunOS Project. All rights reserved.
 */

#include <rsa_test.h>

uint8_t Message[] = {
0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x00, };
uint8_t Digest_Padded[] = {
0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe4, 0x2c, 0x9f, 0x12,
0xf7, 0xd2, 0x67, 0x3a, 0x23, 0xea, 0x85, 0x61, 0xeb, 0xb2, 0xc2, 0x19, 0xdc, 0xd9, 0xf1, 0xaa, };
uint8_t Digest[] = {
0xe4, 0x2c, 0x9f, 0x12, 0xf7, 0xd2, 0x67, 0x3a, 0x23, 0xea, 0x85, 0x61, 0xeb, 0xb2, 0xc2, 0x19,
0xdc, 0xd9, 0xf1, 0xaa, };
uint8_t Digest_Padded_public_encrypt_no_padding_out[] = {
0x51, 0xc1, 0x40, 0x72, 0x4d, 0x11, 0x1b, 0x6e, 0xd1, 0x95, 0xa4, 0x4b, 0x6d, 0x22, 0x87, 0x4c,
0x36, 0x3f, 0x11, 0x20, 0xf4, 0x17, 0x75, 0xb7, 0x7e, 0x7a, 0xa3, 0x0b, 0x0f, 0x34, 0x10, 0xce,
0x65, 0x6d, 0x9b, 0xc5, 0x13, 0x6d, 0x23, 0x56, 0xd4, 0xdf, 0x58, 0x2b, 0x3b, 0x7b, 0x1f, 0x78,
0xc1, 0x42, 0x7a, 0x46, 0x91, 0xd5, 0x78, 0x3e, 0x89, 0x23, 0x84, 0xf4, 0xbc, 0xa4, 0xe3, 0x17,
0xc4, 0x40, 0x4b, 0x25, 0x50, 0x3c, 0x91, 0x8e, 0x60, 0xfa, 0x75, 0x5b, 0xbf, 0x86, 0x1d, 0xcf,
0x29, 0xa6, 0xa9, 0x9d, 0x2c, 0x7a, 0x7e, 0x16, 0x95, 0x5d, 0xa2, 0x72, 0x72, 0x5b, 0xfe, 0x81,
0x27, 0xde, 0x30, 0x19, 0x92, 0x2c, 0x26, 0xf0, 0xc7, 0x16, 0xc8, 0x61, 0xe0, 0x04, 0x52, 0x65,
0xf1, 0x4c, 0x54, 0x10, 0x33, 0xf6, 0xca, 0x74, 0xc5, 0x26, 0x8a, 0x9a, 0xe1, 0x5a, 0x8c, 0xed, };
uint8_t Digest_public_encrypt_pkcs1_padding_out[] = {
0xa0, 0x66, 0x29, 0x7a, 0xa8, 0x36, 0x8b, 0x7c, 0x9b, 0xbf, 0xcb, 0x08, 0x65, 0x55, 0xfc, 0x1d,
0x4a, 0xae, 0x3c, 0x84, 0x21, 0xc2, 0xde, 0x4d, 0x5e, 0xbe, 0xfa, 0x83, 0xe9, 0x4a, 0x93, 0xf4,
0x4c, 0x63, 0xb6, 0x38, 0xad, 0xc5, 0x2d, 0xf1, 0xaf, 0x28, 0xa3, 0x86, 0xfa, 0x17, 0x82, 0x6f,
0xb9, 0x5b, 0xdf, 0x7f, 0x30, 0xfb, 0x54, 0xf9, 0x8c, 0x67, 0x0d, 0x9d, 0xd0, 0x6c, 0x62, 0xfd,
0x72, 0x14, 0x59, 0xca, 0x96, 0xd4, 0x98, 0x5a, 0x9e, 0x15, 0xb4, 0x28, 0x39, 0x34, 0x6a, 0x27,
0x21, 0xc1, 0x61, 0x6c, 0x1a, 0x6c, 0x0e, 0xcd, 0xc1, 0x4e, 0x2f, 0xd1, 0x9e, 0x6b, 0x79, 0x34,
0x80, 0x74, 0x86, 0xf4, 0x3e, 0x96, 0x4f, 0x2b, 0xd9, 0x28, 0xf8, 0x79, 0x29, 0x6d, 0xdf, 0x53,
0x79, 0x50, 0xce, 0xba, 0xf6, 0x28, 0x76, 0x1a, 0x88, 0x19, 0xbf, 0x4e, 0x7e, 0xd5, 0x15, 0x1b, };
uint8_t Digest_signature_pkcs1_padding_out[] = {
0x07, 0x2d, 0x25, 0xde, 0xa5, 0xfd, 0x7c, 0xb0, 0x92, 0xb4, 0xee, 0x57, 0xe8, 0xd3, 0x79, 0x74,
0x59, 0x25, 0x34, 0xef, 0xfd, 0x2b, 0xda, 0x8b, 0xa4, 0x40, 0x4e, 0xd8, 0x92, 0x6e, 0xee, 0x84,
0x52, 0xb0, 0xe1, 0x0e, 0xa8, 0xa9, 0x68, 0x62, 0x1b, 0x51, 0xed, 0x50, 0x84, 0x98, 0x6a, 0x97,
0x98, 0xe8, 0xcf, 0x3f, 0x85, 0xd3, 0x28, 0x26, 0xf3, 0x7a, 0x52, 0x4b, 0x04, 0x95, 0xe6, 0xfd,
0xfa, 0x41, 0xf3, 0xac, 0x8a, 0x6d, 0x74, 0x91, 0x8c, 0x87, 0x52, 0x38, 0x08, 0x49, 0xf4, 0x60,
0xcd, 0x4b, 0x1a, 0x9e, 0x52, 0x60, 0xf2, 0x73, 0x60, 0x31, 0x78, 0x37, 0xd9, 0x42, 0xc4, 0x61,
0x43, 0xcf, 0x6d, 0x55, 0xee, 0x05, 0x19, 0xb7, 0xc3, 0x37, 0xa7, 0xa8, 0xa4, 0xbd, 0xf1, 0xac,
0x8e, 0x39, 0x20, 0x59, 0xcd, 0xfc, 0x50, 0x16, 0x81, 0x2d, 0xeb, 0xba, 0x95, 0xe9, 0x38, 0xa5, };
