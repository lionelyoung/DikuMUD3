/*
 $Author: tperry $
 $RCSfile: mplex.h,v $
 $Date: 2001/04/10 21:11:37 $
 $Revision: 2.0 $
 */

#include "network.h"
#include <string.h>
#include "protocol.h"
#include "essential.h"
#include "queue.h"
#include "hook.h"
#include "color.h"

struct arg_type
{
    int nMotherPort;
    int nMudPort;
    char *pAddress;
    int g_bModeANSI;
    int g_bModeEcho;
    int g_bModeRedraw;
    int g_bModeTelnet;
    int g_bModeRawHTML;
    int bWebSockets;
};

#define Assert(a, b)                                                                                                                       \
    do                                                                                                                                     \
    {                                                                                                                                      \
        if (!(a))                                                                                                                          \
        {                                                                                                                                  \
            fprintf(stderr, "%s\n", b);                                                                                                    \
            assert(a);                                                                                                                     \
        }                                                                                                                                  \
    } while (0);

extern int g_bHadAlarm;
extern struct arg_type g_mplex_arg;
extern char g_mudname[50];

int ParseArg(int argc, char *argv[], struct arg_type *arg);
void bye_signal(int signal);
void alarm_signal(int sig);
