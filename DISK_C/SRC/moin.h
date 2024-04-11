/**********************
 * 关于鼠标使用、人机交互（）检测和返回
 * ********************/
#ifndef _MOIN_H_

#define _MOIN_H_

#include "main.h"

enum bar_testmouse_mode
{
	MOUSETEST_INBAR,
	MOUSETEST_OUTBAR,
	MOUSETEST_ALL
};

enum bar_testmouse_state
{
	MOUSE_INBAR_NO,
	MOUSE_INBAR_L,
	MOUSE_INBAR_R,
	MOUSE_OUTBAR_NO,
	MOUSE_OUTBAR_L,
	MOUSE_OUTBAR_R,
	MOUSE_BAR_EDGE,
	MOUSE_INBAR,
	MOUSE_OUTBAR
};

enum filetest_mode
{
	TREEFILEMODE,
	MAINFILEMODE,
	MAINFILEMODE_LIST,
	MAINFILEMODE_ICON_MIDDLE,
	MAINFILEMODE_ICON_BIG,
	MAINFILEMODE_ICON_SUPER,
	MAINFILEMODE_SEARCH,
};

// enum file_area_number

enum textinput_mode
{
	TEXTDISPLAY,
	TEXTNOTDISPLAY,
};

enum refresh_cursor_write_mode
{
	CURSORWRITE_INPUT_MODE,
	CURSORWRITE_NOTINPUT_MODE,
};

enum whichstate_time
{
	NOW,
	LAST
};

enum line_column
{
	LINE,
	COLUMN,
};

enum filetest_mousepress_state
{
	NOT_INBAR,
	NOPRESS,
	LEFTPRESS,
	RIGHTPRESS,
	OUT_NOPRESS,
	OUT_LEFTPRESS,
	OUT_RIGHTPRESS,
};

enum mousepress_change //状态不变者，为0
{
	PTOP,	  //按下到按下
	PTOB,	  //按下到弹起
	BTOP,	  //弹起到按下
	BTOB = 0, //弹起到弹起
};

/*该定义部分摘自其他头文件，各个按键对应ASCII码值*/
#ifndef NOVIRTUALKEYCODES

#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL 0x03
#define VK_MBUTTON 0x04
#define VK_XBUTTON1 0x05
#define VK_XBUTTON2 0x06
#define VK_BACK 0x08
#define VK_TAB 0x09
#define VK_CLEAR 0x0C
#define VK_RETURN 0x0D
#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
#define VK_MENU 0x12
#define VK_PAUSE 0x13
#define VK_CAPITAL 0x14
#define VK_KANA 0x15
#define VK_HANGEUL 0x15
#define VK_HANGUL 0x15
#define VK_JUNJA 0x17
#define VK_FINAL 0x18
#define VK_HANJA 0x19
#define VK_KANJI 0x19
#define VK_ESCAPE 0x1B
#define VK_CONVERT 0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F
#define VK_SPACE 0x20
#define VK_PRIOR 0x21
#define VK_NEXT 0x22
#define VK_END 0x23
#define VK_HOME 0x24
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_SELECT 0x29
#define VK_PRINT 0x2A
#define VK_EXECUTE 0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT 0x2D
#define VK_DELETE 0x2E
#define VK_HELP 0x2F

#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D
#define VK_SLEEP 0x5F
#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87
#define VK_NUMLOCK 0x90
#define VK_SCROLL 0x91
#define VK_OEM_NEC_EQUAL 0x92
#define VK_OEM_FJ_JISHO 0x92
#define VK_OEM_FJ_MASSHOU 0x93
#define VK_OEM_FJ_TOUROKU 0x94
#define VK_OEM_FJ_LOYA 0x95
#define VK_OEM_FJ_ROYA 0x96
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU 0xA4
#define VK_RMENU 0xA5
#define VK_BROWSER_BACK 0xA6
#define VK_BROWSER_FORWARD 0xA7
#define VK_BROWSER_REFRESH 0xA8
#define VK_BROWSER_STOP 0xA9
#define VK_BROWSER_SEARCH 0xAA
#define VK_BROWSER_FAVORITES 0xAB
#define VK_BROWSER_HOME 0xAC
#define VK_VOLUME_MUTE 0xAD
#define VK_VOLUME_DOWN 0xAE
#define VK_VOLUME_UP 0xAF
#define VK_MEDIA_NEXT_TRACK 0xB0
#define VK_MEDIA_PREV_TRACK 0xB1
#define VK_MEDIA_STOP 0xB2
#define VK_MEDIA_PLAY_PAUSE 0xB3
#define VK_LAUNCH_MAIL 0xB4
#define VK_LAUNCH_MEDIA_SELECT 0xB5
#define VK_LAUNCH_APP1 0xB6
#define VK_LAUNCH_APP2 0xB7
#define VK_OEM_1 0xBA
#define VK_OEM_PLUS 0xBB
#define VK_OEM_COMMA 0xBC
#define VK_OEM_MINUS 0xBD
#define VK_OEM_PERIOD 0xBE
#define VK_OEM_2 0xBF
#define VK_OEM_3 0xC0
#define VK_OEM_4 0xDB
#define VK_OEM_5 0xDC
#define VK_OEM_6 0xDD
#define VK_OEM_7 0xDE
#define VK_OEM_8 0xDF
#define VK_OEM_AX 0xE1
#define VK_OEM_102 0xE2
#define VK_ICO_HELP 0xE3
#define VK_ICO_00 0xE4
#define VK_PROCESSKEY 0xE5
#define VK_ICO_CLEAR 0xE6
#define VK_PACKET 0xE7
#define VK_OEM_RESET 0xE9
#define VK_OEM_JUMP 0xEA
#define VK_OEM_PA1 0xEB
#define VK_OEM_PA2 0xEC
#define VK_OEM_PA3 0xED
#define VK_OEM_WSCTRL 0xEE
#define VK_OEM_CUSEL 0xEF
#define VK_OEM_ATTN 0xF0
#define VK_OEM_FINISH 0xF1
#define VK_OEM_COPY 0xF2
#define VK_OEM_AUTO 0xF3
#define VK_OEM_ENLW 0xF4
#define VK_OEM_BACKTAB 0xF5
#define VK_ATTN 0xF6
#define VK_CRSEL 0xF7
#define VK_EXSEL 0xF8
#define VK_EREOF 0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1 0xFD
#define VK_OEM_CLEAR 0xFE

#endif
/*至此结束*/

#define WORD_WIDTH 8 //宏定义字体宽度（间隔+字宽）

/*****************************
 * 检测鼠标，在框内/框外点击，
 * 在框内点击传递入0，在框外点击传递入1；
 * 传递参数：框四角坐标，模式选择
 * 返回值：在框内未点击传递0，在框内左键点击传递1，在框内右键点击传递2，在框外不点击传递3，
 * 			在框外左键传递4，在框外右键传递5；
 * ****************************/
int testmouse_bar(int x1, int y1, int x2, int y2, int mode);

/********************************
 * FUNCTION:testmouse_inoutbar
 * DESCRIPTION:检测鼠标位置 是否在框内/外
 * INPUT:框四角坐标
 * RETURN:1为在框内，0为在框外
 * OTHERS:无
 ********************************/
int testmouse_inoutbar(int x1, int y1, int x2, int y2);

/*****************
 * 用于图标变化的检测鼠标函数
 * 将上次循环鼠标在/不在的值后移一位，并将本次循环鼠标在/不在的值记录在第二位
 *
 * 传递：矩形边框坐标，state变量的地址
 * 改变state的值
 * ************************/
void testmouse_ico(int x1, int y1, int x2, int y2, State *pstate);

/********************************
 * FUNCTION:get_lc_maindisplay
 * DESCRIPTION:根据文件标号和模式，计算显示位置的行列数
 * INPUT:显示模式，编号
 * RETURN:数组，元素为（1）行数-1（2）列数-1
 * OTHERS:无
 ********************************/
int *get_lc_maindisplay(int type_maindisplay, int num);

/********************************
 * FUNCTION:changemouse_write
 * DESCRIPTION:面向搜索框的鼠标光标改变函数
 * INPUT:搜索框（文本框）四点坐标，此时所处模式
 * RETURN:无
 * OTHERS:在搜索框内则变为工形,不在就不变或者变成缺省光标样式，
 * 			从而实现不断更新鼠标情况下鼠标形式的改变
 ********************************/
void changemouse_write(int x1, int y1, int x2, int y2, int mode);

/********************************
 * FUNCTION:test_filenum_list
 * DESCRIPTION:检测鼠标在文件区的哪个文件区域
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度	//, 检测位置（模式）
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:在调用之前要先确定鼠标此时位于指定有效区域
 ********************************/
int test_filenum_list(int x1, int y1, struct My_filenode *headNode,
					  int height, int width, int mode);

/********************************
 * FUNCTION:test_filenum_list
 * DESCRIPTION:检测鼠标在文件区的文件区域编号，列表显示模式
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度,
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:重载版本
 ********************************/
int test_filenum_list(int x1, int y1, struct My_vector_ *headNode, int height, int width);

/********************************
 * FUNCTION:test_filenum_icon
 * DESCRIPTION:缩略图显示模式（图标），获取鼠标在文件区的文件区域编号
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:在调用之前要先确定鼠标此时位于指定有效区域
 ********************************/
int test_filenum_icon(int x1, int y1, struct My_filenode *headNode);

/********************************
 * FUNCTION:refresh_filetreestate
 * DESCRIPTION:实时检测鼠标，并刷新树形文件区文件块显示状态
 * INPUT:状态数组首地址，目标指针，页数
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filetreestate(int *state, struct My_filenode *pfl, int page);

/********************************
 * FUNCTION:refresh_filemainstate
 * DESCRIPTION:实时刷新主文件区显示状态
 * INPUT:状态数组首地址，目标指针，C盘头指针，页数，
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filemainstate(int *state, struct My_filenode *headnode_current, struct My_filenode *ph, int page);

/********************************
 * FUNCTION:refresh_filesearch_state
 * DESCRIPTION:实时刷新搜索模式主文件区显示状态
 * INPUT:状态数组首地址，目标指针，被复制指针，页数，
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filesearch_state(int *state, struct My_vector_ *headnode_current);

/********************************
 * FUNCTION:test_search_mousepress
 * DESCRIPTION:检测搜索模式双击
 * INPUT:press_last
 * RETURN:-1没双击，正数为序号
 * OTHERS:无
 ********************************/
int test_search_mousepress(int press_last);

/********************************
 * FUNCTION:test_file_mousepress
 * DESCRIPTION:检测鼠标在文件区点击位置
 * INPUT:文件所在链表头节点 ,C盘头指针，检测位置（模式）
 * RETURN:数组,元素---	 （1）框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * 						（2）同（1），相对于大区域
 * 						（3）点击位置对应文件编号
 * OTHERS:实际上只有前几个用到了
 ********************************/
int *test_file_mousepress(struct My_filenode *headnode, My_filenode *ph, int mode);

/********************************
 * FUNCTION:test_file_mousepress
 * DESCRIPTION:检测鼠标在文件区点击位置
 * INPUT:文件所在链表头节点 ,C盘头指针，检测位置（模式）
 * RETURN:数组,元素---	 （1）框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * 						（2）同（1），相对于大区域
 * 						（3）点击位置对应文件编号
 * OTHERS:对于树形文件区的重载版本
 ********************************/
int *test_file_mousepress(struct My_filenode *headnode, char *page);

/********************************
 * FUNCTION:test_mainfile_icon_effec
 * DESCRIPTION:检测主文件区鼠标此时是否处于有效区域
 * INPUT:显示模式
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_mainfile_icon_effec(int type_maindisplay, struct My_filenode *headNode);

/********************************
 * FUNCTION:test_treefile_list_effec
 * DESCRIPTION:检测树形文件区鼠标此时是否处于有效区域
 * INPUT:树形文件区头节点
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_treefile_list_effec(struct My_filenode *headNode);

/********************************
 * FUNCTION:test_mainfile_search_effec
 * DESCRIPTION:检测搜索文件区文件区鼠标此时是否处于有效区域
 * INPUT:头节点
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_mainfile_search_effec(struct My_vector_ *headnode);

/**********************************
 * 对文件进行选中操作
 * 鼠标左键点击某个文件，其被选中，节点相应内容变化，
 * 传递参数：文件所在链表头节点,页数，被点击文件编号，
 * 返回值：无
 * ****************************************/
void refresh_filechstate(struct My_filenode *headNode, struct My_filenode *ph, int page, int);

/********************************
 * FUNCTION:gettype_mainfile_display
 * DESCRIPTION:获取显示模式
 * INPUT:当前目录头节点，C盘头指针
 * RETURN:显示模式（推荐使用宏定义）
 * OTHERS:无
 ********************************/
int gettype_mainfile_display(struct My_filenode *headnode_current, struct My_filenode *ph);

/*******************
 * 背景颜色变化函数
 * 实现鼠标放置在此处变换背景颜色
 * 传递参数：目的矩形位置
 * 无返回值
 * ****************/

/***********************
 * 输入框的人机交互模块
 * 实现进入循环后，实时监测键盘缓冲区，并可以移动鼠标，同时把输入文本显示在屏幕上
 * 支持西文......支持中文好像有点摸不着头脑还是先算了
 * ***********************/

/****************************
 * 键盘交互模块
 * 返回1说明输入有效，0说明无效。
 * 传递参数：字符数组（栈）指针， 输入处坐标，输入框坐标（四个）,输入字体宽度，
 * 			背景颜色，最大容纳字符数，文本输入模式（输入结束后是否继续显示文本）
 * 返回值：无
 * *************************/
void keybdintraction(char *textipt, int x0, int y0, int x1, int y1, int x2, int y2,
					 int width, int bkcolor, int maxnum, int mode, int ifkey);

/*******************************
 * 检测缓冲区函数
 * 若缓冲区有字符,则返回字符的键值（ASCII码）；
 * 若缓冲区无字符，则返回0（NULL的ASCII码）
 * 传递参数：无
 * 返回值：char型数字，可能是0，也可能是有效ASCII码，但是不检测其值
 * *******************************/
char getbuffer_keybd(void);

/***********************************
 * 清除键盘输入缓冲区函数
 * 传递参数：无
 * 返回值：无
 * ************************************/
void clearbuffer_keybd(void);

/********************************
 * FUNCTION:inittimer
 * DESCRIPTION:初始化定时器，精度18.2分之一秒
 * INPUT:无
 * RETURN:无
 * OTHERS:无
 ********************************/
void inittimer(void);

/********************************
 * FUNCTION:judgetimer
 * DESCRIPTION:判断计时函数
 * INPUT:时间间隔（单位为18.2分之一秒）
 * RETURN:0或者1
 * OTHERS:输入时间间隔（），时间达到或者超过设定值返回1并重置计时器，时间未达到设定值返回0
 ********************************/
int judgetimer(long interval);

/*********************************************
 * 输入框刷新函数
 * 显示新字，刷掉旧字
 * 传递参数：文字输入位置坐标，输入框上下输出边界，
 * 			字间隔，字符栈数，输入框背景颜色，字符栈（指针），当前（该循环）获得键盘字符，框容纳最大字符量
 * 返回值：无
 * ********************************************/
void refresh_textbox(int x0, int y0, int y1, int y2, int width, int num,
					 int bkcolor, char *textipt, char temp, int maxnum);

/********************************
 * FUNCTION:
 * DESCRIPTION:密码输入框刷新
 * INPUT:	文字输入位置坐标，输入框上下输出边界，
 * 			字间隔，字符栈数，输入框背景颜色，当前（该循环）获得键盘字符，框容纳最大字符量
 * RETURN:
 * OTHERS:
 ********************************/
void refresh_keybox(int x0, int y0, int y1, int y2, int width, int num,
					int bkcolor, char *textipt, char temp, int maxnum);

/*******************************************
 * 光标显示函数，一闪一闪
 * 传递参数：字符初始位置，字宽，输入框上下有效边界，线宽，线离字间距，线颜色，
 * 		闪烁间隔（18.2分之一秒），字符栈数，光标状态量（0或1）, 背景颜色,最大容纳字符数
 * 返回值：无
 * ****************************************/
void refresh_textcursor(int x0, int width, int y1_, int y2_,
						int L_width, int space, int L_color, int interval,
						int num, char *state, int bkcolor, int maxnum);

/********************************
 * FUNCTION:clear_textcursor
 * DESCRIPTION:清除文本输入光标
 * INPUT:字符初始位置，字宽，输入框上下有效边界，线宽，线离字间距，字符栈数, 背景颜色,最大容纳字符数
 * RETURN:无
 * OTHERS:用于退出输入模式但显示文本的情况，防止刷出来一个去不掉的光标
 ********************************/
void clear_textcursor(int x0, int width, int y1_, int y2_, int L_width, int space,
					  int num, int bkcolor, int maxnum);

/************************************
 * 结束图形化输入模式函数
 * 复原输入框
 * 传递参数：输入框有效边界,背景颜色,结束模式
 * 返回值：无
 * ********************************/
void close_textinput(int x1, int y1, int x2, int y2, int bkcolor, int mode);

/****************************
 * 防止按键连续调用功能（关于长按的适配和按一次随缘调用模块的避免）
 * 传递参数：无
 * 返回值：无
 * ***************************/
void longpress_fit(void);

/**********************************
 * 双击检测函数
 * 最多持续7/9秒，检测是否双击
 * 传递参数：方框坐标
 * 返回值：双击为1，非双击为0
//  * *********************************/
int testmouse_doublepress(int x1, int y1, int x2, int y2);

/********************************
 * 鼠标点击状态变化检测函数
 * 用于检测鼠标状态切换
 * 传递参数：上一个循环鼠标按下状态数据，本次循环鼠标按下状态数据
 * 返回值：0为不变，1为按到不按，2为不按到按
 * ********************************/
int testmouse_presschange(int press_last, int press_new);

/********************************
 * FUNCTION:
 * DESCRIPTION:获取最大显示文件数
 * INPUT:ch,ph
 * RETURN:
 * OTHERS:
 ********************************/
int get_maxfilenum(My_filenode *headnode_current, My_filenode *ph);

#endif