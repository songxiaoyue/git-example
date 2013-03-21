//////////////////////////////////////////////////////////////////////////  
///        COPYRIGHT NOTICE \n 
///        Copyright (c) 2011, SAMSUNG SDSC \n     
///        All rights reserved.  
///  
/// @file    SynCruControl.h  
/// @brief   ͬ���ӿڲ㣺ת���첽�ӿڵ��ã�ʵ��ͬ���ӿ�
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
#define _ESM_CRU_MSG_COIN_IN_ WM_USER+0x300F    //���յ�Ӳ�ҵ�֪ͨ��Ϣ
#endif

#ifndef _ESM_CRU_CHANGE_OK_MSG_
#define _ESM_CRU_CHANGE_OK_MSG_  WM_USER+0x3001     //���㶷�ɹ����ִ�н����Ϣ 
#endif

#ifndef _ESM_CRU_CHANGE_FAIL_MSG_
#define _ESM_CRU_CHANGE_FAIL_MSG_ WM_USER+0x3002    //���㶷���ִ��ʧ�ܣ������Ϣ 
#endif

#ifndef _ESM_CRU_DEV_MSG_
#define _ESM_CRU_DEV_MSG_    WM_USER+0x300E       //Ӳ�ҵ�Ԫ�����Ϣ 
#endif

extern HANDLE g_hEvent;
class AFX_EXT_CLASS CSynCruControl  ///ͬ���ӿڵ�����
{
public:
	///���캯��
	CSynCruControl(void);
public:
	///��������
	~CSynCruControl(void);

public:
	///��ʼ���� ָ�����ںţ�ʵ�ִ�ͨѶ����
	bool FunCRUInit( BYTE port,  HWND hWnd, _LPFNMODULESTATE_ lpfnModuleStatePro_, _LPFNMODUDATAPRO_ lpfnMouleDataPro ); 
	///�豸��������
	int FunCruParaSet( CCruControl::CRU_COIN_LIMIT stInCoinLmt, CCruControl::CRU_COIN_LIMIT stOutCoinLmt, BYTE ucIsRetractFull );
	///�����趨
	int FunCruDataSet( CCruControl::CRU_DATA_SET_PARA_T unCruDataSetPara, BYTE *pucData );
	///�豸����
	int FunResetCRU( enum CCruControl::COIN_DEALWITH_MODE coinDwMode );
	///״̬��ѯ
	int FunStatusInqury();
	///Ͷ�����
	int FunEnableCru();
	///Ͷ���ֹ
	int FunDisableCru();
	///���׿�ʼ
	int FunTransBegin();
	///���׽���
	int FunTransEnd();
	///��������
	int FunReturnCoin();
	///���Ҽ���
	int FunCoinChange(unsigned short ucNum1Yuan, unsigned short ucNum5Jiao);
	///Ӳ�Ҵ���
	int FunCoinCarry();
	///Ӳ�һ���
	int FunCoinClear( CCruControl::CRU_COIN_CLEAR_T unCruCoinClearNum);
	///�жϻ���
	int FunStopClear();
	
	///ģ��״̬�仯����
	void CruModuleStatePro( int nState );
	///CRU����2������3��Ӧ����������
	int CruModuleDataPro( int nDataSize, unsigned char* pData );

public:

	///��е״̬
	typedef union
	{
		BYTE  bzMechanicalState[10];
		struct  
		{
			///װ�ù�ͬ״̬��		
			unsigned char b1DeviceCommConnect:1;
			unsigned char b1DeviceCommCduPdl:1;
			unsigned char b1DeviceCommReserve1:1; 
			unsigned char b1DeviceCommMechPull:1;
			unsigned char b1DeviceCommReserve2:1;
			unsigned char b1DeviceCommReserve3:1;
			unsigned char b1DeviceCommMechNotAction:1;
			unsigned char b1DeviceCommReserve4:1;

			///����װ��״̬��
			unsigned char b2DeviceSpecialReserve1:1;
			unsigned char b2DeviceSpecialReserve2:1;
			unsigned char b2DeviceSpecialReserve3:1;
			unsigned char b2DeviceSpecialCoinAsile:1;
			unsigned char b2DeviceSpecialInsertCoin:1;
			unsigned char b2DeviceSpecialReserve4:1;
			unsigned char b2DeviceSpecialReserve5:1;
			unsigned char b2DeviceSpecialReserve6:1;

			///ѭ��Hopper1Ԫ״̬
			unsigned char b3CycleHopper1YuanEmpty:1;
			unsigned char b3CycleHopper1YuanInterrupt:1;
			unsigned char b3CycleHopper1YuanInterruptNotice:1;
			unsigned char b3CycleHopper1YuanReserve1:1;
			unsigned char b3CycleHopper1YuanFull:1;
			unsigned char b3CycleHopper1YuanInstall:1;
			unsigned char b3CycleHopper1YuanReserve2:1;
			unsigned char b3CycleHopper1YuanNodevice:1;

			///ѭ��Hopper5��״̬
			unsigned char b4CycleHopper5jiaoEmpty:1;
			unsigned char b4CycleHopper5jiaoInterrupt:1;
			unsigned char b4CycleHopper5jiaoInterruptNotice:1;
			unsigned char b4CycleHopper5jiaoReserve1:1;
			unsigned char b4CycleHopper5jiaoFull:1;
			unsigned char b4CycleHopper5jiaoInstall:1;
			unsigned char b4CycleHopper5jiaoReserve2:1;
			unsigned char b4CycleHopper5jiaoNodevice:1;

			///����Ǯ��1Ԫ״̬
			unsigned char b5BackupHopper1YuanEmpty:1;
			unsigned char b5BackupHopper1YuanInterrupt:1;
			unsigned char b5BackupHopper1YuanInterruptNotice:1;
			unsigned char b5BackupHopper1YuanReserve1:1;
			unsigned char b5BackupHopper1YuanFull:1;
			unsigned char b5BackupHopper1YuanInstall:1;
			unsigned char b5BackupHopper1YuanReserve2:1;
			unsigned char b5BackupHopper1YuanNodevice:1;

			///����Ǯ��5��״̬
			unsigned char b6BackupHopper5jiaoEmpty:1;
			unsigned char b6BackupHopper5jiaoInterrupt:1;
			unsigned char b6BackupHopper5jiaoInterruptNotice:1;
			unsigned char b6BackupHopper5jiaoReserve1:1;
			unsigned char b6BackupHopper5jiaoFull:1;
			unsigned char b6BackupHopper5jiaoInstall:1;
			unsigned char b6BackupHopper5jiaoReserve2:1;
			unsigned char b6BackupHopper5jiaoNodevice:1;

			///����Ǯ����ֵreserve1
			unsigned char b7Reserve: 8;
			///����Ǯ����ֵreserve2
			unsigned char b8Reserve: 8;

			///����Ǯ����ֵ1Ԫ
			unsigned char b9BackupValue:8;
			///����Ǯ����ֵ5��
			unsigned char b10BackupValue:8;
		}bMnSymbol;
	}_STAT_CRU_MECHANICAL_T;

	///ö����Ϣ
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


	///����״̬
	typedef union
	{
		BYTE bzActionState[2];
		struct  
		{
			///����״̬��1Byte
			unsigned short bActionStateByte1NoPara : 1;
			unsigned short bActionStateByte1Reserve1 : 1;
			unsigned short bActionStateByte1Reserve2 : 1;
			unsigned short bActionStateByte1InputAllow : 1;
			unsigned short bActionStateByte1Reserve3 : 1;
			unsigned short bActionStateByte1Reserve4 : 1;
			unsigned short bActionStateByte1SafeCoverAction : 1;
			unsigned short bActionStateByte1MechanAction : 1;

			///����״̬��2Byte
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

	///������Ϣ
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
	///�����Ϣ
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

	///������Ϣ
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

	///MTC��Ϣ
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
	typedef struct	CRU_STATE ///��ETC Code�Ƶ�
	{
		enum  COMM_STATE///ͨѶ״̬
		{
			CommUnknown,///δ֪
			CommOk,		///ͨѶ����
			CommErr,	///ͨѶ����
			CommFail	///ͨѶ���ϣ����Ӵ���
		}CommState;

		enum CONNECT_STATE///����״̬������ʱ����״̬��ȡ�źţ�ȷ�����ӡ�����ʹ����δȷ����Ҳ���ܶ�����
		{
			ConnectUnknown, ///δ֪
			Connected,  ///�����ѽ���
			NotConnect ///����δ����
		}ConnectState;

		enum  CRU_DEVICE_STATE ///CRU�豸״̬
		{
			StateUnknown, ///δ֪
			StateOk,    /// ״̬����
			stateWarning,  ///�豸����
			StateError,    ///�豸�쳣
			cmdException,  ///�����쳣
		}CruDeviceState;

		enum  JAM_STATE ///����״̬
		{
			JamUnknown, ///δ֪
			JamOk,      ///����
			JamHappen,  ///����
		}JamState;

		enum  SEQUENCE_STATE
		{
			SequenceUnknown, ///δ֪
			SequenceOk,      ///����˳������
			SequenceErr     ///�쳣
		}SequenceState;
		
		enum  SENSOR_STATE
		{
			SensorUnknown, ///δ֪
			SensorOk,      ///����
			SensorErr,     ///����
		}SensorState;
		
		enum  HDRDWARD_STATE
		{
			HdUnknown,  ///δ֪
			HdOk,		///����
			HdErr,		///����
		}HdState;
		
		enum  MECHANICAL_STATE
		{
			MechaUnknown,   ///��е״̬δ֪
			MechaNormal,    ///��е״̬����
			ChangeNotice,   ///�յ���е״̬�仯֪ͨ����Ҫ��ѯ״̬��ȷ���豸�������
		}MechanicalState;
	}TCruMdState;

	class CCoinBox	///Ǯ���ඨ��
	{
	public:
		CCoinBox( void );
		~CCoinBox( void );

		typedef	struct	TBOX_STATE	///Ǯ��״̬����
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
	///����Ӳ��ģ�� ��״̬����Ϣ.
	TCruMdState		m_CruState; 
	CCoinBox		m_nCoinBoxA;
	CCoinBox		m_nCoinBoxB;
	CCoinBox		m_nCoinBoxC;
	CCoinBox		m_nCoinBoxD;
	//WORD            m_wResCode;

public:
	///��ǰ���Ӧ��Ϣ�ṹ�壬���������Ӧ��ͬ�����д����������status��Ӧ��
	typedef struct  
	{
		///���ӦID
		WORD wCurCmdRspID;
		///���ӦRES����
		WORD wCurCmdRspRes;
	}_CRU_CMD_RSP_INFO;
	
	///��ǰ���Ӧ��Ϣ
	_CRU_CMD_RSP_INFO m_CurCmdRspInfo;
	///�ϴ����Ӧ��Ϣ
	_CRU_CMD_RSP_INFO m_LastCmdRspInfo;

private:
	CCruModuleComm* m_CruComm;
	CCruControl m_cruControl;
	DWORD m_dwCmdTimeOut;    //����ִ�г�ʱʱ��
	HWND m_hWnd;             //���淢�ͽ�����Ϣ�ľ��

private:
	//����ERROR CODE״̬��
	void MTCPro(BYTE *pData);   
	//��Ӧ��ͬ���֣�����RES����������
	void CruCommonRspPro( unsigned char* pData );
	//������Ϣ��������
	void CruInCoinInfoRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//������Ϣ��������
	void CruOutCoinInfoRspPro( unsigned char* pData );
	//�����Ϣ��������
	void CruClearCoinInfoRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//�豸�������÷�Ӧ����������
	void FunParaSetRspPro( unsigned char* pData );
	//�����趨��Ӧ����������
	void FunDataSetRspPro( unsigned char* pData );
	//�豸���÷�Ӧ����������
	void FunResetRspPro( unsigned char* pData );
	//״̬��ѯ��Ӧ����������
	void FunStatusRspPro( unsigned char* pData );
	//Ͷ����ɷ�Ӧ����������
	void FunEnableRspPro( unsigned char* pData);
	//Ͷ���ֹ��Ӧ����������
	void FunDisableRspPro( unsigned char* pData);
	//���׿�ʼ��Ӧ����������
	void FunTransBeginRspPro( unsigned char* pData );
	//���׽�����Ӧ����������
	void FunTransEndRspPro( unsigned char* pData );
	//����������Ӧ����������
	void FunReturnCoinRspPro( unsigned char* pData );
	//���Ҽ�����Ӧ����������
	void FunCoinChangeRspPro( unsigned char* pData );
	//Ӳ�Ҵ��ͷ�Ӧ����������
	void FunCoinCarryRspPro( unsigned char* pData );
	//Ӳ�һ��շ�Ӧ����������
	void FunCoinClearRspPro( unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//�жϻ��շ�Ӧ����������
	void FunStopClearRspPro( unsigned char* pData );
	//��е�仯֪ͨ����������
	void FunMechaChangeNoticeRspPro(unsigned char* pData, WPARAM& wParam, LPARAM& lParam );
	//�������֪ͨ����������
	void FunStartupOverRspPro( unsigned char* pData );
};
