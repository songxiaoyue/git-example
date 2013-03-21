//////////////////////////////////////////////////////////////////////////  
///        COPYRIGHT NOTICE \n 
///        Copyright (c) 2011, SAMSUNG SDSC \n     
///        All rights reserved.  
///  
/// @file    SynCruControl.h  
/// @brief   同步接口层：转换异步接口调用，实现同步接口
///  
///
///  
/// @version   1.0.0.1   
/// @author    SongJian
/// @date      2011-7-19
///  
///  
///  
//////////////////////////////////////////////////////////////////////////  
#pragma once
#include "CruModuleComm.h"
#include "CruControl.h"
#pragma pack(push)
#pragma pack(1)

#pragma warning( disable : 4200 )           // nonstandard extension used : zero-sized array in struct/union

#ifndef _ESM_CRU_MSG_COIN_IN_
#define _ESM_CRU_MSG_COIN_IN_ WM_USER+0x300F    //接收到硬币的通知消息
#endif

#ifndef _ESM_CRU_CHANGE_OK_MSG_
#define _ESM_CRU_CHANGE_OK_MSG_  WM_USER+0x3001     //找零斗成功清币执行结果信息 
#endif

#ifndef _ESM_CRU_CHANGE_FAIL_MSG_
#define _ESM_CRU_CHANGE_FAIL_MSG_ WM_USER+0x3002    //找零斗清币执行失败，结果信息 
#endif

#ifndef _ESM_CRU_DEV_MSG_
#define _ESM_CRU_DEV_MSG_    WM_USER+0x300E       //硬币单元检测信息 
#endif

extern HANDLE g_hEvent;
class AFX_EXT_CLASS CSynCruControl  ///同步接口导出类
{
public:
	///构造函数
	CSynCruControl(void);
public:
	///析构函数
	~CSynCruControl(void);

public:
	///初始操作 指定串口号，实现打开通讯握手
	bool FunCRUInit( BYTE port,  HWND hWnd, _LPFNMODULESTATE_ lpfnModuleStatePro_, _LPFNMODUDATAPRO_ lpfnMouleDataPro ); 
	///设备参数设置
	int FunCruParaSet( CCruControl::CRU_COIN_LIMIT stInCoinLmt, CCruControl::CRU_COIN_LIMIT stOutCoinLmt, BYTE ucIsRetractFull );
	///数据设定
	int FunCruDataSet( CCruControl::CRU_DATA_SET_PARA_T unCruDataSetPara, BYTE *pucData );
	///设备重置
	int FunResetCRU( enum CCruControl::COIN_DEALWITH_MODE coinDwMode );
	///状态查询
	int FunStatusInqury();
	///投入许可
	int FunEnableCru();
	///投入禁止
	int FunDisableCru();
	///交易开始
	int FunTransBegin();
	///交易结束
	int FunTransEnd();
	///保留返还
	int FunReturnCoin();
	///出币计数
	int FunCoinChange(unsigned short ucNum1Yuan, unsigned short ucNum5Jiao);
	///硬币传送
	int FunCoinCarry();
	///硬币回收
	int FunCoinClear( CCruControl::CRU_COIN_CLEAR_T unCruCoinClearNum);
	///中断回收
	int FunStopClear();
	
	///模块状态变化处理
	void CruModuleStatePro( int nState );
	///CRU类型2、类型3反应包解析函数
	int CruModuleDataPro( int nDataSize, unsigned char* pData );

public:

	///机械状态
	typedef union
	{
		BYTE  bzMechanicalState[10];
		struct  
		{
			///装置共同状态字		
			unsigned char b1DeviceCommConnect:1;
			unsigned char b1DeviceCommCduPdl:1;
			unsigned char b1DeviceCommReserve1:1; 
			unsigned char b1DeviceCommMechPull:1;
			unsigned char b1DeviceCommReserve2:1;
			unsigned char b1DeviceCommReserve3:1;
			unsigned char b1DeviceCommMechNotAction:1;
			unsigned char b1DeviceCommReserve4:1;

			///个别装置状态字
			unsigned char b2DeviceSpecialReserve1:1;
			unsigned char b2DeviceSpecialReserve2:1;
			unsigned char b2DeviceSpecialReserve3:1;
			unsigned char b2DeviceSpecialCoinAsile:1;
			unsigned char b2DeviceSpecialInsertCoin:1;
			unsigned char b2DeviceSpecialReserve4:1;
			unsigned char b2DeviceSpecialReserve5:1;
			unsigned char b2DeviceSpecialReserve6:1;

			///循环Hopper1元状态
			unsigned char b3CycleHopper1YuanEmpty:1;
			unsigned char b3CycleHopper1YuanInterrupt:1;
			unsigned char b3CycleHopper1YuanInterruptNotice:1;
			unsigned char b3CycleHopper1YuanReserve1:1;
			unsigned char b3CycleHopper1YuanFull:1;
			unsigned char b3CycleHopper1YuanInstall:1;
			unsigned char b3CycleHopper1YuanReserve2:1;
			unsigned char b3CycleHopper1YuanNodevice:1;

			///循环Hopper5角状态
			unsigned char b4CycleHopper5jiaoEmpty:1;
			unsigned char b4CycleHopper5jiaoInterrupt:1;
			unsigned char b4CycleHopper5jiaoInterruptNotice:1;
			unsigned char b4CycleHopper5jiaoReserve1:1;
			unsigned char b4CycleHopper5jiaoFull:1;
			unsigned char b4CycleHopper5jiaoInstall:1;
			unsigned char b4CycleHopper5jiaoReserve2:1;
			unsigned char b4CycleHopper5jiaoNodevice:1;

			///备用钱箱1元状态
			unsigned char b5BackupHopper1YuanEmpty:1;
			unsigned char b5BackupHopper1YuanInterrupt:1;
			unsigned char b5BackupHopper1YuanInterruptNotice:1;
			unsigned char b5BackupHopper1YuanReserve1:1;
			unsigned char b5BackupHopper1YuanFull:1;
			unsigned char b5BackupHopper1YuanInstall:1;
			unsigned char b5BackupHopper1YuanReserve2:1;
			unsigned char b5BackupHopper1YuanNodevice:1;

			///备用钱箱5角状态
			unsigned char b6BackupHopper5jiaoEmpty:1;
			unsigned char b6BackupHopper5jiaoInterrupt:1;
			unsigned char b6BackupHopper5jiaoInterruptNotice:1;
			unsigned char b6BackupHopper5jiaoReserve1:1;
			unsigned char b6BackupHopper5jiaoFull:1;
			unsigned char b6BackupHopper5jiaoInstall:1;
			unsigned char b6BackupHopper5jiaoReserve2:1;
			unsigned char b6BackupHopper5jiaoNodevice:1;

			///备用钱箱面值reserve1
			unsigned char b7Reserve: 8;
			///备用钱箱面值reserve2
			unsigned char b8Reserve: 8;

			///备用钱箱面值1元
			unsigned char b9BackupValue:8;
			///备用钱箱面值5角
			unsigned char b10BackupValue:8;
		}bMnSymbol;
	}_STAT_CRU_MECHANICAL_T;

	///枚数信息
	typedef union
	{
		BYTE bzNumberInfo[16];
		struct
		{
			unsigned short usHopper1YuanNum : 16;
			unsigned short usHopper5JiaoNum : 16;
			unsigned short usBackup1YuanNum : 16;
			unsigned short usBackup5JiaoNum : 16;
			unsigned short usRetract1YuanNum : 16;
			unsigned short usRetract5JiaoNum : 16;
			unsigned short usReserve1 : 16;
			unsigned short usReserve2 : 16;
		}bNumberInfo;
	}_CRU_BOX_NUMBER_INFO_T;


	///动作状态
	typedef union
	{
		BYTE bzActionState[2];
		struct  
		{
			///动作状态第1Byte
			unsigned short bActionStateByte1NoPara : 1;
			unsigned short bActionStateByte1Reserve1 : 1;
			unsigned short bActionStateByte1Reserve2 : 1;
			unsigned short bActionStateByte1InputAllow : 1;
			unsigned short bActionStateByte1Reserve3 : 1;
			unsigned short bActionStateByte1Reserve4 : 1;
			unsigned short bActionStateByte1SafeCoverAction : 1;
			unsigned short bActionStateByte1MechanAction : 1;

			///动作状态第2Byte
			unsigned short bActionStateByte2Reserve1 : 1;
			unsigned short bActionStateByte2Retracting : 1;
			unsigned short bActionStateByte2AutoGiveback : 1;
			unsigned short bActionStateByte2Reserve2 : 1;
			unsigned short bActionStateByte2Reserve3 : 1;
			unsigned short bActionStateByte2Reserve4 : 1;
			unsigned short bActionStateByte2Reserve5 : 1;
			unsigned short bActionStateByte2Reserve6 : 1;
		}bActionByte;
	}_CRU_ACTION_STATE_T;

	///进币信息
	typedef union
	{
		BYTE bzInCoinInfo[8];
		struct  
		{
			unsigned int iEscrowCoin1YuanNum : 16;
			unsigned int iEscrowCoin5JiaoNum : 16;
			unsigned int iRejectCoinNum : 16;
			unsigned int iOverflowCoinNum : 16;
		}bInCoinInfo;
	}_CRU_BOX_INCOIN_INFO_T;
	///清币信息
	typedef union
	{
		BYTE bzClearCoinInfo[8];
		struct  
		{
			unsigned int iHopper1YuanToCoinBoxNum : 16;
			unsigned int iHopper5JiaoToCoinBoxNum : 16;
			unsigned int iBackup1ToCoinBoxNum : 16;
			unsigned int iBackup2ToCoinBoxNum : 16;
		}bClearBoxInfo;
	}_CRU_BOX_CLEARCOIN_INFO_T;

	///出币信息
	typedef union
	{
		BYTE bzOutCoinInfo[8];
		struct  
		{
			unsigned short usNumber1Yuan : 16;
			unsigned short usNumber5Jiao : 16;
			unsigned short usReserved1 : 16;
			unsigned short usReserved2 : 16;
		}bOutCoinInfo;
	}_CRU_BOX_OUTCOIN_INFO_T;

	///MTC信息
	typedef union
	{
		BYTE bzMtcCode[4];
		struct 
		{
			unsigned int iMtcReserve1 : 4;
			unsigned int iMtcReserve2 : 4;
			unsigned int iMtcMCType : 8;
			unsigned int iMtcActionForm : 4;
			unsigned int iMtcErrorReason : 4;
			unsigned int iMtcErrorDetail : 8;
		}bMtcCode;
	}_CRU_MTC_CODE_T;

public:
	_STAT_CRU_MECHANICAL_T m_bMechaState;
	_CRU_MTC_CODE_T m_bMtcCode;
	_CRU_BOX_NUMBER_INFO_T m_bBoxNumberInfo;
	_CRU_BOX_INCOIN_INFO_T m_bInCoinInfo;
	_CRU_BOX_OUTCOIN_INFO_T m_bOutCoinInfo;
	_CRU_BOX_CLEARCOIN_INFO_T m_bClearCoinInfo;

public:
	typedef struct	CRU_STATE ///从ETC Code推导
	{
		enum  COMM_STATE///通讯状态
		{
			CommUnknown,///未知
			CommOk,		///通讯正常
			CommErr,	///通讯错误
			CommFail	///通讯故障，连接错误
		}CommState;

		enum CONNECT_STATE///连接状态，启动时接收状态读取信号，确立连接。但即使连接未确立，也可能动作。
		{
			ConnectUnknown, ///未知
			Connected,  ///连接已建立
			NotConnect ///连接未建立
		}ConnectState;

		enum  CRU_DEVICE_STATE ///CRU设备状态
		{
			StateUnknown, ///未知
			StateOk,    /// 状态正常
			stateWarning,  ///设备警告
			StateError,    ///设备异常
			cmdException,  ///命令异常
		}CruDeviceState;

		enum  JAM_STATE ///堵塞状态
		{
			JamUnknown, ///未知
			JamOk,      ///正常
			JamHappen,  ///堵塞
		}JamState;

		enum  SEQUENCE_STATE
		{
			SequenceUnknown, ///未知
			SequenceOk,      ///命令顺序正常
			SequenceErr     ///异常
		}SequenceState;
		
		enum  SENSOR_STATE
		{
			SensorUnknown, ///未知
			SensorOk,      ///正常
			SensorErr,     ///故障
		}SensorState;
		
		enum  HDRDWARD_STATE
		{
			HdUnknown,  ///未知
			HdOk,		///正常
			HdErr,		///故障
		}HdState;
		
		enum  MECHANICAL_STATE
		{
			MechaUnknown,   ///机械状态未知
			MechaNormal,    ///机械状态正常
			ChangeNotice,   ///收到机械状态变化通知，需要查询状态，确认设备连接情况
		}MechanicalState;
	}TCruMdState;

	class CCoinBox	///钱箱类定义
	{
	public:
		CCoinBox( void );
		~CCoinBox( void );

		typedef	struct	TBOX_STATE	///钱箱状态定义
		{
			enum {
				StateUnknown,
				StateOk,
				StateErr,
			}BoxState;
			enum {
				ExistUnknown,
				Nodevice,
				Exist,
				NoneExist,
			}ExistState;
			enum {
				IDUnknown,
				IDOk,
				IDErr,			
			}IDState;
			enum {
				SpaceUnkown,
				Empty,
				NearEmpty,
				Normal,
				Full,
			}SpaceState;
		}TBoxState,*pstBoxState;

	public:
		TBoxState m_stBoxState;
	};

public:
	///保存硬币模块 的状态和信息.
	TCruMdState		m_CruState; 
	CCoinBox		m_nCoinBoxA;
	CCoinBox		m_nCoinBoxB;
	CCoinBox		m_nCoinBoxC;
	CCoinBox		m_nCoinBoxD;
	//WORD            m_wResCode;

public:
	///当前命令反应信息结构体，用于在命令反应共同函数中处理特殊命令（status反应）
	typedef struct  
	{
		///命令反应ID
		WORD wCurCmdRspID;
		///命令反应RES代码
		WORD wCurCmdRspRes;
	}_CRU_CMD_RSP_INFO;
	
	///当前命令反应信息
	_CRU_CMD_RSP_INFO m_CurCmdRspInfo;
	///上次命令反应信息
	_CRU_CMD_RSP_INFO m_LastCmdRspInfo;

private:
	CCruModuleComm* m_CruComm;
	CCruControl m_cruControl;
	DWORD m_dwCmdTimeOut;    //命令执行超时时间
	HWND m_hWnd;             //保存发送进币消息的句柄

private:
	//处理ERROR CODE状态字
	void MTCPro(BYTE *pData);   
	//反应共同部分（包括RES）解析函数
	void CruCommonRspPro( unsigned char* pData );
	//进币信息解析函数
	void CruInCoinInfoRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//出币信息解析函数
	void CruOutCoinInfoRspPro( unsigned char* pData );
	//清币信息解析函数
	void CruClearCoinInfoRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//设备参数设置反应包解析函数
	void FunParaSetRspPro( unsigned char* pData );
	//参数设定反应包解析函数
	void FunDataSetRspPro( unsigned char* pData );
	//设备重置反应包解析函数
	void FunResetRspPro( unsigned char* pData );
	//状态查询反应包解析函数
	void FunStatusRspPro( unsigned char* pData );
	//投入许可反应包解析函数
	void FunEnableRspPro( unsigned char* pData);
	//投入禁止反应包解析函数
	void FunDisableRspPro( unsigned char* pData);
	//交易开始反应包解析函数
	void FunTransBeginRspPro( unsigned char* pData );
	//交易结束反应包解析函数
	void FunTransEndRspPro( unsigned char* pData );
	//保留返还反应包解析函数
	void FunReturnCoinRspPro( unsigned char* pData );
	//出币计数反应包解析函数
	void FunCoinChangeRspPro( unsigned char* pData );
	//硬币传送反应包解析函数
	void FunCoinCarryRspPro( unsigned char* pData );
	//硬币回收反应包解析函数
	void FunCoinClearRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//中断回收反应包解析函数
	void FunStopClearRspPro( unsigned char* pData );
	//机械变化通知包解析函数
	void FunMechaChangeNoticeRspPro(unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//启动完毕通知包解析函数
	void FunStartupOverRspPro( unsigned char* pData );
};
