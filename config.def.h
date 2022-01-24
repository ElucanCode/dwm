/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;           /* border pixel of windows */
static const unsigned int gappx     = 10;           /* gaps between windows */
static const unsigned int snap      = 32;          /* snap pixel */
static const unsigned int systraypinning = 0;      /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor x */
static const unsigned int systrayonleft = 0;       /* 0: systray on the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;      /* systray spacing */
static const int systraypinningfailfirst = 1;     /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor */
static const int showsystray        = 1;           /* 0 means no systray */
static const int showbar            = 1;           /* 0 means no bar */
static const int topbar             = 1;           /* 0 means bottom bar */
static const Bool viewontag         = True;        /* follow window to tag it is moved to */
static const char *fonts[]          = { "source code pro:size=8", "fontawesome:size=10" };
static const char dmenufont[]       = "source code pro:size=8";
static const char col_background[]  = "#1d1d1d";   /* background color */
static const char col_inactive[]    = "#606060";   /* inactive window border color */
static const char col_font[]        = "#bbbbbb";   /* font color */
static const char col_current[]     = "#eeeeee";   /* current tag and current window color */
static const char col_selected[]    = "#a54949";   /* Top bar second color and active window border color */
static const char col_floating[]    = "#008cda";   /* border color for floating windows */
static const char *colors[][4]      = {
	/*               fg           bg               border         float*/
	[SchemeNorm] = { col_font,    col_background,  col_inactive,  col_inactive },
	[SchemeSel]  = { col_current, col_selected,    col_selected,  col_floating },
};

static const char *const autostart[] = {
	"nitrogen", "--restore", NULL,
	"alacritty", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = {
	"",  /* 1 - terminal */
       	"",  /* 2 - web applications (firefox, ...) */
       	"",  /* 3 - fileexplorer */
       	"",  /* 4 - communication,mails,... */
       	"",  /* 5 - privacy (tor, password-manager) */
       	"",  /* 6 - documents and files */
       	"",  /* 7 - virtual machines */
       	"",  /* 8 - system (htop, ...) */
       	""   /* 9 - settings */
};

static const char *defaulttagapps[] = {
	"alacritty",              /* 1 */ 
	"firefox",                /* 2 */ 
	"pcmanfm",                /* 3 */ 
	"thunderbird",            /* 4 */ 
	"torbrowser-launcher",    /* 5 */ 
	NULL,                     /* 6 */ 
	NULL,                     /* 7 */ 
	NULL,                     /* 8 */ 
	NULL                      /* 9 */ 
};

static const Rule rules[] = {
	/* class         instance    title     tags mask     floating   monitor */
	{ "Alacritty",   NULL,       NULL,     1,            0,         -1 },
	{ "firefox",     NULL,       NULL,     1 << 1,       0,         -1 },
	{ "ranger",      NULL,       NULL,     1 << 3,       0,         -1 },
	{ "pcmanfm",     NULL,       NULL,     1 << 3,       0,         -1 },
	{ "Thunderbird", NULL,       NULL,     1 << 4,       0,         -1 },
	{ "Tor Browser", NULL,       NULL,     1 << 6,       0,         -1 },
};

/* layout(s) */
static const float mfact     = 0.55;   /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;      /* number of clients in master area */
static const int resizehints = 1;      /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;   /* 1 will force focus on the fullscreen window */
static const int attachdirection = 3;  /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

#include "gaplessgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },         /* first entry is default */
	{ "><>",      NULL },         /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "###",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_background, "-nf", col_font, "-sb", col_selected, "-sf", col_current, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,      spawndefault,   {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
/*	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },*/
/*	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },*/
/*	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },*/
	{ MODKEY,                       XK_n,      shiftview,      {.i = 1  } },
	{ MODKEY,                       XK_p,      shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_a,      scratchpad_show, {.i = 1} },
	{ MODKEY,                       XK_y,      scratchpad_show, {.i = 2} },
	{ MODKEY,                       XK_x,      scratchpad_show, {.i = 3} },
	{ MODKEY|ShiftMask,             XK_a,      scratchpad_hide, {.i = 1} },
	{ MODKEY|ShiftMask,             XK_y,      scratchpad_hide, {.i = 2} },
	{ MODKEY|ShiftMask,             XK_x,      scratchpad_hide, {.i = 3} },
	{ MODKEY|ShiftMask,             XK_r,      scratchpad_remove, { 0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask|ControlMask, XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask|ControlMask, XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

