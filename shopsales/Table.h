#include"Configure.h"
#include "Basicwidget.h"
#include<vector>
#include "Goods.h"
#include "buyer.h"
class Table :public Basicwidget
{	public:


	 Table(int row, int col);
	void setRowCount(int row); //���ñ�� ������
	void setColCount(int col);// ����б�
	void setHeader(const std ::string & header);  //���ö�����  book��
	void insertData (std::vector<Goods>& booklist1); //�������� book��
	Table();
	void setHeader2(const std::string& header);//���� buyer�� ��ͷ
	void insertData2(std::vector<membercard>& booklist1);//���� buyer�� ���� 

	void show();
	int m_rows; //������ 
	int m_cols;
	int m_gridH, m_gridW;//�߶ȣ���� 

	void drawTableGrid();  //����
	void drawTableData();//������ ����û�� ȫ��insertdata�� ��
	std:: string m_header;  //��� ����Ϣ
	std::vector <std::string> m_datas; // ���ݼ��� 

	void  insertGoods(Goods& b); // ¼������ 
	void  insertbuyer(membercard& b); //¼������ 
};
