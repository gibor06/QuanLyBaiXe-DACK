#include "DuongBao.h"

void initSList(SList& sl)
{
	sl.Head = sl.Tail = NULL;
}

int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	return 0;
}

void initSListNV(SListNV& dsnv)
{
	dsnv.Head = dsnv.Tail = NULL;
}

int isEmpty(SListNV dsnv)
{
	if (dsnv.Head == NULL)
		return 1;
	return 0;
}

int insertHead(SList& sl, SNode* p)
{
	if (isEmpty(sl) == 1)
	{
		sl.Head = sl.Tail = p;
		return 1;
	}

	p->Next = sl.Head;
	sl.Head = p;

	return 1;
}

int insertTail(SList& sl, SNode* p)
{
	if (isEmpty(sl) == 1)
	{
		sl.Head = sl.Tail = p;
		return 1;
	}

	sl.Tail->Next = p;
	sl.Tail = p;

	return 1;
}

int insertTailNV(SListNV& sl, SNodeNV* p) {	//Thêm node p vào đầu danh sách
	if (p == NULL) {
		return 0;
	}
	if (isEmpty(sl) == 1) {
		sl.Head = p;
		sl.Tail = p;
	}
	else {
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}

int deleteHead(SList& sl, Itemtype& x)
{
	if (isEmpty(sl) == 1)
		return 0;

	SNode* p = sl.Head;
	sl.Head = p->Next;
	if (sl.Head == NULL)
		sl.Tail = NULL;

	x = p->Info;
	delete p;
	return 1;
}

int deleteTail(SList& sl, Itemtype& x)
{
	if (isEmpty(sl) == 1)
		return 0;

	SNode* p = sl.Tail;
	SNode* q = sl.Head;

	if (p == q)
		sl.Head = sl.Tail = NULL;

	else
	{
		while (q->Next != p)
		{
			q = q->Next;
		}

		sl.Tail = q;
		q->Next = NULL;
	}

	x = p->Info;
	delete p;
	return 1;
}

int deleteBefore(SList& sl, Itemtype& x, SNode* q)
{
	if (isEmpty(sl) == 1 || q == NULL || q->Next == NULL)
		return 0;

	SNode* p = q->Next;
	if (q->Next == sl.Head)
	{
		deleteTail(sl, x);
		return 1;
	}

	q->Next = p->Next;

	x = p->Info;
	delete p;
	return 1;
}

int deleteAfter(SList& sl, Itemtype& x, SNode* q)
{
	if (isEmpty(sl) == 1 || q == NULL || q == sl.Head)
		return 0;

	if (q == sl.Head->Next)
	{
		deleteHead(sl, x);
		return 1;
	}

	SNode* r = sl.Head;
	SNode* p = r->Next;

	while (p->Next != q)
	{
		r = p;
		p = p->Next;
	}

	r->Next = q;
	x = p->Info;

	delete p;
	return 1;

}

SNode* createSNode(Itemtype x)
{
	SNode* p = new SNode;
	if (p == NULL)
		return NULL;

	p->Info = x;
	p->Next = NULL;

	return p;
}

SNodeNV* createSNodeNV(NV x)
{
	SNodeNV* p = new SNodeNV;
	if (p == NULL)
		return NULL;

	p->Info = x;
	p->Next = NULL;

	return p;
}

void swap(Itemtype& a, Itemtype& b)
{
	Itemtype c = a;
	a = b;
	b = c;
}

void timeAuto(int *hour, int *minute, int *day, int *month, int *year)
{
	// cập nhật thời gian tự động
	time_t t;
	struct tm *tm_info;

	time(&t);
	tm_info = localtime(&t);

	*hour = tm_info->tm_hour;
	*minute = tm_info->tm_min;

	*day = tm_info->tm_mday;
	*month = tm_info->tm_mon + 1;      // tm_mon: 0-11, nên cần +1
	*year = tm_info->tm_year + 1900;   // tm_year: số năm tính từ 1900
}

int namNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		return 1;
	return 0;
}

int soNgayTrongThang(int thang, int nam)
{
	switch (thang)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
	{
			   return 31;
			   break;
	}
	case 2:
	{
			  if (namNhuan(nam))
			  {
				  return 29;
			  }
			  return 28;
	}
	case 4:case 6:case 9:case 11:
	{
			   return 30;
	}
	}
}

int countAllXeTrongBai(SList sl){
	// đếm toàn bộ xe trong bãi
	if (isEmpty(sl) == 1){
		return 0;
	}
	int count = 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next){
		count++;
	}
	return count;
}

int countXeTheoLoai(SList sl, char *loaiXe) {
	//đếm xe theo loại
	if (isEmpty(sl)) {
		return 0;
	}
	int count = 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		if (stricmp(p->Info.LX, loaiXe) == 0)
			count++;
	}
	return count;
}

int countLoaiXeNhieuNhatTrongBai(SList sl)
{
	if (isEmpty(sl) == 1)
		return 0;

	int demMax = 0;
	SList dsthongTinMax;
	initSList(dsthongTinMax);

	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		int dem = 1;
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (strcmpi(p->Info.LX, q->Info.LX) == 0)
				dem++;
		}

		if (dem > demMax)
		{
			initSList(dsthongTinMax); // tao 1 danh sach max
			demMax = dem;
			SNode* M = createSNode(p->Info);
			insertTail(dsthongTinMax, M);
		}

		if (dem == demMax)
		{
			// Kiểm tra trùng lặp
			int daCo = 0;
			for (SNode* q = dsthongTinMax.Head; q != NULL; q = q->Next)
			{
				if (strcmpi(q->Info.LX, p->Info.LX) == 0)
				{
					daCo = 1;
					break;
				}
			}
			if (daCo == 0)
			{
				SNode* M = createSNode(p->Info);
				insertTail(dsthongTinMax, M);
			}
		}
	}

	printf("LOAI XE XUAT HIEN NHIEU NHAT TRONG BAI:\n");
	if (isEmpty(dsthongTinMax) == 1)
	{
		printf("DANH SACH TRONG.\n");
	}

	else
	{
		for (SNode* p = dsthongTinMax.Head; p != NULL; p = p->Next)
		{
			printf("%s: %d chiec\n", p->Info.LX, demMax);
		}
	}
	return demMax;
}

StackNode* createStackNode(Itemtype x)
{
	StackNode* p = new StackNode;
	if (p == NULL)
		return NULL;

	p->Info = x;
	p->Next = NULL;

	return p;
}

void initStack(Stack& st)
{
	st.Top = NULL;
}

int isEmptyStack(Stack st)
{
	if (st.Top == NULL)
		return 1;

	return 0;
}

int PUSH(Stack& st, StackNode* p)
{
	if (p == NULL)
		return 0;

	if (isEmptyStack(st) == 1)
	{
		st.Top = p;
		return 1;
	}

	p->Next = st.Top;
	st.Top = p;
	return 1;
}

int POP(Stack& st, Itemtype& x)
{
	if (isEmptyStack(st) == 1)
		return 0;

	StackNode* p = st.Top;
	st.Top = st.Top->Next;

	x = p->Info;

	delete p;
	return 1;
}

void getTop(Stack st)
{
	if (isEmptyStack(st) == 0)
		printf("%d\n", st.Top->Info);
	else
		printf("NULL\n");
}

int demNV(SListNV dsnv)
{
	if (isEmpty(dsnv) == 1){
		return 0;
	}
	int count = 0;
	for (SNodeNV* p = dsnv.Head; p != NULL; p = p->Next){
		count++;
	}
	return count;
}

int saveTTNV(SListNV& dsnv, char FILENAME[]) {
	FILE* fo = fopen(FILENAME, "wt");
	if (fo == NULL) {
		printf("Loi khi mo file.\n");
		return 0;
	}

	int dem = demNV(dsnv);

	fprintf(fo, "%d\n", dem);

	for (SNodeNV* p = dsnv.Head; p != NULL; p = p->Next)
	{
		fprintf(fo, "%s#%s#%s#%s\n", p->Info.maNV, p->Info.tenNV, p->Info.chucVu, p->Info.matKhau);
	}

	fclose(fo);
	return 1;
}

void nhapTTNV(nhanVien &x){
	//Nhap thong tin nhan vien
	printf("Nhap ma nhan vien: ");
	rewind(stdin);
	gets_s(x.maNV);
	printf("Nhap ho va ten nhan vien: ");
	rewind(stdin);
	gets_s(x.tenNV);
	printf("Nhap chuc vu: ");
	rewind(stdin);
	gets_s(x.chucVu);
	printf("Nhap mat khau dang nhap: ");
	rewind(stdin);
	gets_s(x.matKhau);
}

void xuatTTNV(NV x){
	printf("%-20s%-35s%-20s%-15s\n", x.maNV, x.tenNV, x.chucVu, x.matKhau);
}

void showDSNV(SListNV dsnv) {
	if (isEmpty(dsnv) == 1) {
		printf("KHONG CO NHAN VIEN NAO!\n\n");
		return;
	}
	printf("DANH SACH NHAN VIEN\n");
	int stt = 1;
	printf("%-5s%-20s%-35s%-20s%-20s\n", "STT", "MA SO NHAN VIEN", "HO VA TEN NHAN VIEN", "CHUC VU", "MAT KHAU");
	for (SNodeNV* p = dsnv.Head; p != NULL; p = p->Next)
	{
		printf("%-5d", stt++);
		xuatTTNV(p->Info);
	}
}

void loadTTNV(FILE* fi, NV &x)
{
	fscanf(fi, "%[^#]#%[^#]#%[^#]#%[^\n]\n", x.maNV, x.tenNV, x.chucVu, x.matKhau);
}

void createSListDSNV_FromTextFile(SListNV& dsnv, char inputFilename[]) {
	initSListNV(dsnv);
	FILE* fi = fopen(inputFilename, "rt");
	if (fi == NULL) {
		printf("Mo loi file: %s\n", inputFilename);
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);
	int i = 0;
	NV x;
	while (i < n) {
		loadTTNV(fi, x);
		SNodeNV* p = createSNodeNV(x);
		int kq = insertTailNV(dsnv, p);
		if (kq == 1)
			i++;
	}
}

SNodeNV* findSNode_TheoMSNV(SListNV dsnv, NV nv) {

	if (isEmpty(dsnv) == 1)
		return NULL;

	for (SNodeNV* p = dsnv.Head; p != NULL; p = p->Next) {
		if (strcmpi(p->Info.maNV, nv.maNV) == 0)
			return p;
	}
	return NULL;
}

void showTTNVTheoMa(SListNV dsnv, NV x) {
	if (isEmpty(dsnv) == 1)
		return;

	SNodeNV *f = findSNode_TheoMSNV(dsnv, x);
	if (f != NULL) {
		printf("\nThong tin nhan vien co ma so %s: \n", x.maNV);
		printf("%-20s%-35s%-20s%-20s\n", "MA SO NHAN VIEN", "HO VA TEN NHAN VIEN", "CHUC VU", "MAT KHAU");
		xuatTTNV(f->Info);
	}
	else
		printf("Khong tim thay nhan vien voi ma so: %s\n", x.maNV);
}

int deleteHeadNV(SListNV& sl, NV& x) {
	if (isEmpty(sl) == 1) {
		return 0;
	}
	SNodeNV* p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL) {
		sl.Tail = NULL;
	}
	x = p->Info;	//Lay thong tin nut bi huy
	delete p;		//Huy nut do p tro den
	return 1;
}

int deleteAfterNV(SListNV& dsnv, SNodeNV* q, NV& x) {
	if (q == NULL || q->Next == NULL)
		return 0;
	SNodeNV* p = q->Next;
	q->Next = p->Next;
	if (p == dsnv.Tail)	//Neu node bi xoa la node cuoi
		dsnv.Tail = q;
	x = p->Info;		//Lay thong tin cua node bi huy
	delete p;
	return 1;
}

int deleteTailNV(SListNV& nv, NV& x)
{
	if (isEmpty(nv) == 1)
		return 0;

	SNodeNV* p = nv.Tail;
	SNodeNV* q = nv.Head;

	if (p == q)
		nv.Head = nv.Tail = NULL;

	else
	{
		while (q->Next != p)
		{
			q = q->Next;
		}

		nv.Tail = q;
		q->Next = NULL;
	}

	x = p->Info;
	delete p;
	return 1;
}

int deleteNhanVienTheoMa(SListNV& dsnv, NV& nv) {

	printf("NHAP MA NHAN VIEN CAN XOA: ");
	rewind(stdin);
	gets_s(nv.maNV);

	SNodeNV* q = findSNode_TheoMSNV(dsnv, nv);
	if (q == NULL)
		return 0;

	nv = q->Info; //lưu lại trước khi xóa

	if (q == dsnv.Head)
	{
		deleteHeadNV(dsnv, nv);
	}

	else if (q == dsnv.Tail)
	{
		deleteTailNV(dsnv, nv);
	}

	else
	{
		SNodeNV* p = q->Next;
		deleteAfterNV(dsnv, p, nv);
	}
}