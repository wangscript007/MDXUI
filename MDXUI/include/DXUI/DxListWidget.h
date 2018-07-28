#pragma once
#include "DxWindow.h"
#include "DxScrollBar.h"

namespace DxUI{
	class CDxListItem;
	//+------------------------------------
	//
	// �б���
	// ��ͬ�� CDxListWindow
	// ��ʹ������ģ��
	//
	//+-------------------------------------
	class DXUI_API CDxListWidget :
		public CDxWindow
	{
		DECLARE_CLASS(CDxListWidget)
	public:
		CDxListWidget();
		~CDxListWidget();


		void				SetMultSelectedEnable(bool isMultSelected);
		void				AddItem(CDxListItem* item);
		bool				Empty() const;
		int					Size() const;
		void				RemoveItem(int index);

		CDxListItem*		FirstItem() const;
		CDxListItem*		LastItem() const;
		CDxListItem*		GetCurrentItem() const;
		CDxListItem*		GetItemByIndex(int index) const;
		CDxListItem*		GetItemByText(const MString& Text) const;
		int					GetIndexByItem(CDxListItem* item) const;

		TL::Vector<CDxListItem*> GetAllItem() const;
		TL::Vector<CDxListItem*> GetSelected() const;

		MString				GetItemText(int index) const;
		void				SetSelected(int index);

		void				Clear();

		void				OnResizeEvent();
		void				OnForceUpdate();
		virtual void		OnItemsChanged();


		bool				OnNotify(DXNotifyUI* NotifyEvent);
		void				ReceiveEvent(CDxUIEvent* e);


		void				OnRendWindow(IPainterInterface* painter);


		//
		// ��ѡ��ı�ʱ�����ú������ú�����ͨ��TL::MTLDataBind::Connect ���к��ⲿͨ��
		// void testFun(int index1, int index2);
		// DxUI::CDxListWindow list;
		// TL::MTLDataBind::Connect(MSIGNAL(DxUI::CDxListWindow, SelectedChanged, &list),TL::MSLOT(testFun));
		// 
		void				SelectedChanged(int curIndex, int preIndex, CDxWidget* sender);
		void				SelectedIterms(TL::Vector<int> selecteditems, CDxWidget* sender);


		int					GetMaxHeight() const; // ��ȡ����Ҫ�ĸ߶ȡ�����ʹ�ù�����
		int					GetMaxWidth() const;  // ��ȡ����Ҫ�Ŀ��ȡ�����ʹ�ù�����


	protected:
		void				OnDealItemForDistance(int disx, int disy);
		void				UpdateScrollBarPos();

	private:
		CDxVerticalScrollBar		mVerticalScrollBar;
		CDxHorizonScrollBar			mHorizonScrollBar;
		TL::Vector<CDxListItem*>	mItems;
		int							mItemMaxWidth{ 0 };
		int							mItemMaxHeight{ 0 };
		int							mXCurrentOffset{ 0 };		// ��ǰƫ�ƾ���
		int							mYCurrentOffset{ 0 };		// ��ǰƫ�ƾ���
		int							mXMaxOffset{ 0 };			// ���ƫ�ƾ���
		int							mYMaxOffset{ 0 };			// ���ƫ�ƾ���
		int							mCurrentSelectedIndex{ -1 }; // ��ǰѡ�е�����
		TL::Vector<int>				mSelectedIndexs;             // ��ǰ����ѡ�е�����
		bool						bIsMultSelectedEnabel{ false };
		CDxListItem*				pCurrentItem{ nullptr };	 // ��ǰѡ�е�item
		
	};
}

