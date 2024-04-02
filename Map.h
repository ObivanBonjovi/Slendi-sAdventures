
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

const int H = 27;
const int W = 180;
int cubX = 40, cubY = 50;

String TileMap[H] =
{
	//1                                //3                            //0                    //4                          //2                              //Boss zi
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                          0                           0  0                    0  0       y         0        0000            0000000000000000000000000000000000000000000000000000000",
"0              h           0                           0  0                    0  0       y    O    0        000             0          00000000000000000000000000000000000000000000",
"0       sssssssssssss      0lssssssssssssssE           0  0lsh    esssssp    sp0  0       y         0        00              0r         00000000000000000000000000000000000000000000",
"0       0ZZ         0lE    0                           0  000l          0  Zp000  0       y  hhh b  0        00    essssssssp0lssssE    00000000000000000000000000000000000000000000",
"0   h   0                  0                           0     0l         0 5Z0     0       essssssssp0        0                          00000000000000000000000000000000000000000000",
"0   O   0 b               e0                           0     00lsEjjjjjj0lsp0     0l                         0                          00000000000000000000000000000000000000000000",
"0lsssssp0lss               0          essss  q         0                          00l                        0                        sp00000000000000000000000000000000000000000000",
"0          0l         q    0              0lssssssssssp0                          000l                       0                        0000000000000000000000000000000000000000000000",
"0           0lsssssssss    0ZZZZZZZZ  ZZ               0            ss            0000l                      0l  ss                   0000000000000000000000000000000000000000000000",
"0                     0    0Z         ZZ               0          ep00lE          00000l              m      00uu00lsssssssssssssssssp0000000000000000000000000000000000000000000000",
"0                     0E   0Z         ZZ               0   3                  4   000000        s            0             Z            00000000000000000Z                     ZZZZ0",
"0                          0Z  sssssss                 0  kcn                kcn  000000zzzzzzzz0sE          0                          00000000000000000Z                         0",
"0                          0Z  ZZZZZZZ                 0                          000000lssssssp0           e0                     s    00000000000000000Z                        Z0",
"0    sE   q         qessssp0Z                          0                          0    m                     0szzzs                0 h  00000000000000000Z     z      zsssE       Z0",
"0    0                     0Z                          0         ssssssss         0                          00lsp0zzzs   ss      e0lssp00000000000000000   ssssssssssp0          Z0",
"0E   0                     0lssssssssss            s   0ggggesssp00000000lsssEgggg0                       ssp000000lsp0zzz00            00000000000000000   o  rRR                e0",
"0    0                     000000000000l           0   0                          0                       0  0       00lsp00zzz         00000000000000000   0  hRR                 0",
"0    0                     0000000000000lsssssssssp0  e0                          0         m      z      0  0O      0000000lsssE       00000000000000000  e0  bRR                 0",
"0   e0                     0                  ZZ       0E                        e0          kn    s    ep0  0lE      0                 00000000000000000   0  ssss          Zs    0",
"0                          0                           0    1                2    0                          0        0                 00000000000000000   0          eE         h0",
"0                          0          b                0   kcn              kcn   0sE         s              0b       0  s  s           00000000000000000E  0                     e0",
"0lssssEq          q   esssp0  O     hhs         s      0                          0           0              0lssss                ssssp00000000000000000   0sq                   Z0",
"0                          0lssszzzzsp0   z   zz0lzzssp0            ss            0           0zzzzzzzzzzzzzz000000       qq       0000000000000000000000   00q                   Z0",
"0                          00000lssp000lsssssssp00000000lssssssssssp00lssssssssssp0lsssssssssp0lssssssssssssp000000lssssssssssssssp0000000000000000000000sss00sssssssssssssssssssss0",
"0zzzzzzzzzzzzzzzzzzzzzzzzzz000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0lssssssssssssssssssssssssp000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

