#pragma once
#include "DxLabel.h"
#include "DxScrollBar.h"
#include "DxDataMode.h"
#include "DxWindow.h"


namespace DxUI{

	class CDxListItem;

	//+------------------------------------
	//
	// �б���
	//
	//+-------------------------------------
	class DXUI_API CDxListWindow :
		public CDxWindow
	{
		DECLARE_CLASS(CDxListWindow)
	public:
		CDxListWindow();
		~CDxListWindow();

	
		void				SetMultSelectedEnable(bool isMultSelected);
		void				SetItemDataFactory(CDxListDataMode* item);
		void				SetItemFactory(CDxListItem* item);


		void				AddItem(const MString& itemText);
		void				AddItem(const MString& Icon,const MString& itemText);
		void				AddItems(const TL::Vector<MString>& items);
		void				AddItemsWithIco(const TL::Vector<std::pair<MString, MString>>& items);
		void				AddAnyItem(const mj::MAny& any, const MString& itemText);

		bool				Empty() const;
		int					Size() const;
		bool				IsContainText(const MString& Text); 


		void				RemoveItem(int index);


		CDxListDataMode*	FirstItem() const;
		CDxListDataMode*	LastItem() const;
		CDxListDataMode*	GetCurrentItem() const;
		CDxListDataMode*	GetItemByIndex(int index) const;
		CDxListDataMode*	GetItemByText(const MString& Text) const;
		int					GetIndexByItem(CDxListDataMode* item) const;
		TL::Vector<MString> GetAllItem() const;
		TL::Vector<int>     GetSelectedIndex() const;
		TL::Vector<MString> GetSelected() const;
		TL::Vector<MString> GetAllItem();
		TL::Vector<MString> GetSelected();

		MString				GetItemText(int index) const;
		void				SetSelected(int index);
		void				SetSelected(const TL::Vector<int>& indexs);
		void				SelectedAll();
		void				DeSelectedAll();

		void				Clear();

		void				OnResizeEvent();
		virtual void		OnItemsChanged();


		bool				OnNotify(DXNotifyUI* NotifyEvent);
		void				ReceiveEvent(CDxUIEvent* e);


		void				OnRendWindow(IPainterInterface* painter);


		//
		// ��ѡ��ı�ʱ�����ú������ú�����ͨ��TL::MTLDataBind::Connect ���к��ⲿͨ��
		// void testFun(int index1, int index2);
		// DxUI::CDxListWindow list;
		// TL::MTLDataBind::Connect(MSIGNAL(DxUI::CDxListWindow, SelectedChanged, &list),TL::MSLOT(testFun));
		// ItemChecked ���ڿ�ѡ�е�item��˵�����и��ź�
		// 
	msignals:
		void				SelectedChanged(int curIndex, int preIndex,CDxWidget* sender); 
		void				SelectedIterms(TL::Vector<int> selecteditems, CDxWidget* sender);
		void				ItemChecked(bool isChecked,int curIndex, CDxWidget* sender);
		void				ItemClicked(int index, MString Text, CDxWidget* sender);
		void				ItemClickedPoint(int index, MString Text,POINT pt, CDxWidget* sender);
		void				DoubleClicked(int index, MString Text, CDxWidget* sender);


	public:
		int					GetMaxHeight() const; // ��ȡ����Ҫ�ĸ߶ȡ�����ʹ�ù�����
		int					GetMaxWidth() const;  // ��ȡ����Ҫ�Ŀ��ȡ�����ʹ�ù�����


	protected:
		void				OnDealItemForDistance(int disx,int disy);
		void				UpdateScrollBarPos();
		void				OnItemChecked(bool isChecked, CDxWidget* sender);


	private:
		CDxHorizonScrollBar			mHorizonScrollBar;
		CDxVerticalScrollBar		mVerticalScrollBar;

		TL::Vector<CDxListDataMode*> mListDatas;
		TL::Vector<CDxListItem*>	mItems;
		std::map<CDxListItem*, unsigned> mWindowMapToData; // ��ͼ�����ݵ�ӳ��

		CDxListDataMode*			pDataFactory{ nullptr };
		CDxListItem*				pItemFactory{ nullptr };
		CDxListItem*				pCurrentItem{ nullptr };
		int							mItemMaxWidth{ 0 };
		int							mItemMaxHeight{ 0 };
		int							mXCurrentOffset{ 0 };		// ��ǰƫ�ƾ���
		int							mYCurrentOffset{ 0 };		// ��ǰƫ�ƾ���
		int							mXMaxOffset{ 0 };			// ���ƫ�ƾ���
		int							mYMaxOffset{ 0 };			// ���ƫ�ƾ���

		int							mCurrentSelectedIndex{ -1 }; // ��ǰѡ�е�����
		TL::Vector<int>				mSelectedIndexs;             // ��ǰ����ѡ�е�����
		bool						bIsMultSelectedEnabel{ false };
	};



	//+---------------------------------
	//
	// ������ͷ
	//
	//+-----------------------------------
	class DXUI_API CDxListWindowEx : public CDxWindow{
		DECLARE_CLASS(CDxListWindowEx)
	public:
		CDxListWindowEx();
		~CDxListWindowEx();
		void				SetMultSelectedEnable(bool isMultSelected);
		void				SetItemDataFactory(CDxListDataMode* item);
		void				SetItemFactory(CDxListItem* item);


		void				AddItem(const MString& itemText);
		void				AddItem(const MString& Icon, const MString& itemText);
		void				AddItems(const TL::Vector<MString>& items);
		void				AddItemsWithIco(const TL::Vector<std::pair<MString, MString>>& items);
		void				AddAnyItem(const mj::MAny& any, const MString& itemText);

		bool				Empty() const;
		int					Size() const;
		bool				IsContainText(const MString& Text);

		void				RemoveItem(int index);


		CDxListDataMode*	FirstItem() const;
		CDxListDataMode*	LastItem() const;
		CDxListDataMode*	GetCurrentItem() const;
		CDxListDataMode*	GetItemByIndex(int index) const;
		CDxListDataMode*	GetItemByText(const MString& Text) const;
		int					GetIndexByItem(CDxListDataMode* item) const;
		TL::Vector<MString> GetAllItem() const;
		TL::Vector<MString> GetSelected() const;
		TL::Vector<int>     GetSelectedIndex() const;

		MString				GetItemText(int index) const;
		void				SetSelected(int index);

		void				SetSelected(const TL::Vector<int>& indexs);
		void				SelectedAll();
		void				DeSelectedAll();

		void				Clear();

		void				SetText(const MString& Text);

		//
		// ѡ�����ı�ʱ�����źŻᱻ����
		// ItemChecked ���item��ѡʱѡ��״̬�����ı�ʱ���͸��ź�
		// ItemClicked item�����ʱ���͸��ź�
		// ItemClickedPoint �Ҽ����ʱ���͸��ź�
		// DoubleClicked ˫��ʱ���͸��ź�
		//
	msignals:
		void				SelectedChanged(int curIndex, int preIndex, CDxWidget* sender);
		void				SelectedIterms(TL::Vector<int> selecteditems, CDxWidget* sender);
		void				ItemChecked(bool isChecked, int curIndex, CDxWidget* sender);
		void				ItemClicked(int index, MString Text, CDxWidget* sender);
		void				ItemClickedPoint(int index, MString Text, POINT pt, CDxWidget* sender);
		void				DoubleClicked(int index, MString Text, CDxWidget* sender);

	public:
		int					GetMaxHeight() const; // ��ȡ����Ҫ�ĸ߶ȡ�����ʹ�ù�����
		int					GetMaxWidth() const;  // ��ȡ����Ҫ�Ŀ��ȡ�����ʹ�ù�����

		void				OnItemsChanged();
		void				OnRendWindow(IPainterInterface* painter);

	private:
		CDxListWindow*		p_ListWindow{ nullptr };
		CDxLabel*			p_HeaderLabel{ nullptr };
	};
}

