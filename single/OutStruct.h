#ifndef OUTSTRUCT_H_
#define OUTSTRUCT_H_

#pragma pack(push,1)

#define ASK_ALL		-1

//NTimeʱ����Ϣ
typedef struct tag_NTime
{
	unsigned short	year;
	unsigned char	month;
	unsigned char	day;
	unsigned char	hour;
	unsigned char	minute;
	unsigned char	second;
}NTime;

//��������
typedef struct tag_HISDAT
{
	NTime Time;				//ʱ��
	float Open;				//���̼�
	float High;				//��߼�
	float Low;				//��ͼ�
	float Close;			//���̼�
	union
	{
		float	Amount;		//�ɽ����
		DWORD	VolInStock;	//�ֲ���(�ڻ���Ч)
	};
	float fVolume;			//�ɽ���
	union 
	{ 
		float Settle;		//�����(�ڻ���Ч)
		long  lYClose;		//
		struct
		{   
			WORD up;		//���Ǽ���(ָ����Ч)
			WORD down;		//�µ�����(ָ����Ч)
		}zd;
	};
}HISDAT,*LPHISDAT;

//��������(�ڶ���)
typedef struct tag_REPORTDAT2
{
	DWORD	ItemNum;            // ��������
	float   Close;              // ǰ���̼�
	float   Open;               // ���̼�
	float   Max;                // ��߼�
	float   Min;                // ��ͼ�
	float   Now;                // �ּ�
	DWORD	RefreshNum;			// ˢ����
	DWORD   Volume;             // ����
	DWORD   NowVol;             // ����(���ֲ�)
	float   Amount;             // �ܳɽ����
	DWORD   Inside;             // ����
	DWORD   Outside;            // ����
	float   TickDiff;           // ���ǵ�(��λ��)
	BYTE	InOutFlag;			// �����̱�־ 0:Buy 1:Sell 2:None
	DWORD   CJBS;				// �ɽ�����
	float	Jjjz;				// ����ֵ
	union
	{
		struct	//����
		{
			float	Buyp[5];	// ��������
			DWORD	Buyv[5];	// ��Ӧ�������۵��������
			float	Sellp[5];	// ���������
			DWORD	Sellv[5];	// ��Ӧ��������۵��������
		}Ggpv;
		struct	//ָ��
		{
			float	LxValue;	// ����ָ��
			float	Yield;		// ������Ȩ��ָ��
			long	UpHome;		// ���Ǽ���
			long	DownHome;	// �µ�����
		}Zspv;
	}Other;
	char	ununsed[20];		//����
}REPORTDAT2,*LPREPORTDAT2;


//Ʒ�ֻ�������
typedef struct tag_STOCKINFO 
{
	char        Name[9];			// ֤ȯ����

	short       Unit;               // ���׵�λ	
	long		VolBase;			// ���ȵĻ���
	short		Fz[8];				// ������ʱ��(4��)
	short		InitTimer;			// ��ʼ��ʱ��
	short		EndTimer;			// ����ʱ��
	short		nDelayMin;			// ��ʱ������

	char		bBelongHS300;		// �Ƿ����ڻ���300���
	char		bBelongHasKQZ;		// �Ƿ����ں���תծ���
	char		nBelongRZRQ;		// �Ƿ�����������ȯ���
	
	char		bQH;				// �Ƿ����ڻ�Ʒ��
	char		bHKGP;				// �Ƿ��Ǹ۹�Ʒ��
	short		QHVol_BaseRate;		// �ڻ���ÿ�ֳ���
	float		MinPrice;			// ��С�䶯��λ
	char		unused[1];			// ����

	float       ActiveCapital;		// ��ͨ�ɱ�
    long        J_start;			//��������
	short       J_addr;				//����ʡ��
	short       J_hy;				//������ҵ
    float       J_zgb;				//�ܹɱ�
    float       J_zjhhy;			//֤�����ҵ
    float       J_oldjly;			//������ھ�����
    float       J_oldzysy;			//�������Ӫҵ����
    float       J_bg;				//B��
    float       J_hg;				//H��
    float       J_mgsy2;			//����ÿ������ (�Ʊ����ṩ��ÿ������,������Ĳ���)
    float       J_zzc;				//���ʲ�(Ԫ)
    float       J_ldzc;				//�����ʲ�
    float       J_gdzc;				//�̶��ʲ�
    float       J_wxzc;				//�����ʲ�
    float       J_gdrs;				//�ɶ�����
    float       J_ldfz;				//������ծ
    float       J_cqfz;				//�����ɶ�Ȩ��
    float       J_zbgjj;			//�ʱ�������
    float       J_jzc;				//�ɶ�Ȩ��(���Ǿ��ʲ�)
    float       J_yysy;				//Ӫҵ����
    float       J_yycb;				//Ӫҵ�ɱ�
    float       J_yszk;				//Ӧ���ʿ�
    float       J_yyly;				//Ӫҵ����
    float       J_tzsy;				//Ͷ������
    float       J_jyxjl;			//��Ӫ�ֽ�����
    float       J_zxjl;				//���ֽ�����
    float       J_ch;				//���
    float       J_lyze;				//�����ܶ�
    float       J_shly;				//˰������
    float       J_jly;				//������
    float       J_wfply;			//δ��������
    float       J_mgjzc2;			//����ÿ�ɾ��ʲ� (�Ʊ����ṩ��ÿ������,������Ĳ���)
	float		J_jyl;				//������%
	float		J_mgwfp;			//ÿ��δ����
	float		J_mgsy;				//ÿ������(�����ȫ���)
	float		J_mggjj;			//ÿ�ɹ�����
	float		J_mgjzc;			//ÿ�ɾ��ʲ�
	float		J_gdqyb;			//�ɶ�Ȩ���
}STOCKINFO,*LPSTOCKINFO;

//�ɱ��ܹɱ���Ϣ
typedef struct tag_GBInfo
{
	float Zgb;
	float Ltgb;
}GBINFO,*LPGBINFO;

//��Ʊ�ǵ�ͣ�۸�����
typedef struct tag_TPPrice
{
	float Close;
	float TPTop;
	float TPBottom;
}TPPRICE,*LPTPPRICE;

//���ݻص�������
#define PER_MIN5		0		//5��������
#define PER_MIN15		1		//15��������
#define PER_MIN30		2		//30��������
#define PER_HOUR		3		//1Сʱ����
#define PER_DAY			4		//��������
#define PER_WEEK		5		//��������
#define PER_MONTH		6		//��������
#define PER_MIN1		7		//1��������
#define PER_MINN		8		//���������(10)
#define PER_DAYN		9		//����������(45)
#define PER_SEASON		10		//��������
#define PER_YEAR		11		//��������
#define PER_SEC5		12		//5����
#define PER_SECN		13		//������(15)
#define PER_PRD_DIY0	14		//DIY����
#define PER_PRD_DIY10	24		//DIY����

#define REPORT_DAT2		102	//��������(�ڶ���)
#define GBINFO_DAT		103	//�ɱ���Ϣ
#define	STKINFO_DAT		105	//��Ʊ�������

#define TPPRICE_DAT		121		//�ǵ�ͣ����

#pragma pack(pop)
#endif
