#pragma once
#include "DuongBao.h"

#define MaxCho 300

// Nhập và lưu
void nhapNgayThangNam(int& ngay, int& thang, int& nam)
{
	do
	{
		printf("Nhap ngay: ");
		scanf("%d", &ngay);

		printf("Nhap thang: ");
		scanf("%d", &thang);

		printf("Nhap nam: ");
		scanf("%d", &nam);

		if (ngay < 1 || (ngay > soNgayTrongThang(thang, nam)) || (thang > 12 && thang < 1))
			printf("Vui long xem lai!\n");

	} while (ngay < 1 || (ngay > soNgayTrongThang(thang, nam)) || (thang > 12 && thang < 1));
}

void nhapThoiGianVao(Itemtype& x)
{
	nhapNgayThangNam(x.gioVao.ngay, x.gioVao.thang, x.gioVao.nam);

	do
	{
		printf("Nhap gio: ");
		scanf("%d", &x.gioVao.gio);

	} while (x.gioVao.gio < 0 || x.gioVao.gio > 23);

	do
	{
		printf("Nhap phut: ");
		scanf("%d", &x.gioVao.phut);

	} while (x.gioVao.phut < 0 || x.gioVao.phut > 59);
}

void nhapThoiGianRa(Itemtype& x)
{
	do
	{
		nhapNgayThangNam(x.gioRa.ngay, x.gioRa.thang, x.gioRa.nam);

		do
		{
			printf("Nhap gio: ");
			scanf("%d", &x.gioRa.gio);

		} while (x.gioRa.gio < 0 || x.gioRa.gio > 23);

		do
		{
			printf("Nhap phut: ");
			scanf("%d", &x.gioRa.phut);

		} while (x.gioRa.phut < 0 || x.gioRa.phut > 59);

		if (
			(x.gioVao.ngay > x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam) ||
			(x.gioVao.ngay == x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam && x.gioVao.gio > x.gioRa.gio) ||
			(x.gioVao.ngay == x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam && x.gioVao.gio == x.gioRa.gio && x.gioVao.phut > x.gioRa.phut) ||
			(x.gioVao.thang > x.gioRa.thang && x.gioVao.nam == x.gioRa.nam) || (x.gioVao.nam > x.gioRa.nam)
			)

			printf("Vui long xem lai!\n");

	} while
		(
		(x.gioVao.ngay > x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam) ||
		(x.gioVao.ngay == x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam && x.gioVao.gio > x.gioRa.gio) ||
		(x.gioVao.ngay == x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam && x.gioVao.gio == x.gioRa.gio && x.gioVao.phut > x.gioRa.phut) ||
		(x.gioVao.thang > x.gioRa.thang && x.gioVao.nam == x.gioRa.nam) || (x.gioVao.nam > x.gioRa.nam)
		);


}

void nhap1Xe(Itemtype& x)
{
	printf("Nhap ma xe: ");
	rewind(stdin);
	gets_s(x.MX);

	printf("Nhap bien so xe: ");
	rewind(stdin);
	gets_s(x.BSX);

	printf("Nhap loai xe: ");
	rewind(stdin);
	gets_s(x.LX);

	printf("Nhap ten chu xe: ");
	rewind(stdin);
	gets_s(x.TenChuXe);

	int chon;

	printf("1: TU DONG\n");
	printf("2: NHAP THU CONG\n");
	printf("BAN MUON NHAP THOI GIAN TU DONG HAY THU CONG: ");
	scanf("%d", &chon);

	switch (chon)
	{
	case 1:
	{
			  timeAuto(&x.gioVao.gio, &x.gioVao.phut, &x.gioVao.ngay, &x.gioVao.thang, &x.gioVao.nam);
			  break;
	}

	case 2:
	{
			  nhapThoiGianVao(x);
			  break;
	}
	default:
		printf("KHONG CO CHUC NANG NAY.\n");
		break;
	}
}

int saveVaoDsXeVaoBai(SList dsVao, char FILENAME[])
{
	// luu lai danh sach

	FILE* f = fopen(FILENAME, "wt");

	if (f == NULL)
	{
		printf("Khong mo duoc file du lieu!\n");
		return 0;
	}

	int n = countAllXeTrongBai(dsVao);

	fprintf(f, "%d\n", n);

	for (SNode* p = dsVao.Head; p != NULL; p = p->Next)
	{
		fprintf(f, "%s#%s#%s#%s#%d#%d#%d#%d#%d\n", p->Info.MX, p->Info.BSX, p->Info.LX
			, p->Info.TenChuXe, p->Info.gioVao.ngay
			, p->Info.gioVao.thang, p->Info.gioVao.nam
			, p->Info.gioVao.gio, p->Info.gioVao.phut);
	}

	fclose(f);
	return 1;
}

int saveVaoDsXeRaBai(SList dsRa, char FILENAME[])
{
	// luu lai danh sach

	FILE* f = fopen(FILENAME, "wt");

	if (f == NULL)
	{
		printf("Khong mo duoc file du lieu!\n");
		return 0;
	}

	int n = countAllXeTrongBai(dsRa);

	fprintf(f, "%d\n", n);

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		fprintf(f, "%s#%s#%s#%s#%d#%d#%d#%d#%d#%d#%d#%d#%d#%d#%d\n", p->Info.MX, p->Info.BSX, p->Info.LX
			, p->Info.TenChuXe, p->Info.gioVao.ngay
			, p->Info.gioVao.thang, p->Info.gioVao.nam
			, p->Info.gioVao.gio, p->Info.gioVao.phut, p->Info.gioRa.ngay
			, p->Info.gioRa.thang, p->Info.gioRa.nam
			, p->Info.gioRa.gio, p->Info.gioRa.phut, p->Info.giaGui);
	}

	fclose(f);
	return 1;
}

int loadfileXeVao(SList& dsVao, char FILENAME[])
{ // file xe vào không có giờ ra.
	initSList(dsVao);
	Itemtype x;
	int n;

	FILE* fi = fopen(FILENAME, "r");

	if (fi == NULL)
	{
		printf("Khong mo duoc file du lieu!\n");
		return 0;
	}

	fscanf(fi, "%d\n", &n);

	for (int i = 1; i <= n; i++)
	{
		fscanf(fi, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#%d\n", x.MX, x.BSX, x.LX
			, x.TenChuXe, &x.gioVao.ngay
			, &x.gioVao.thang, &x.gioVao.nam
			, &x.gioVao.gio, &x.gioVao.phut);
		SNode*p = createSNode(x);
		if (p == NULL)
		{
			printf("LOI!");
			return 0;
		}

		insertTail(dsVao, p);
	}

	fclose(fi);
	return 1;
}

int loadfileLichSuXeTrongBai(SList& dsRa, char FILENAME[])
{
	initSList(dsRa);
	Itemtype x;
	int n;

	FILE* fi = fopen(FILENAME, "r");

	if (fi == NULL)
	{
		printf("Khong mo duoc file du lieu!\n");
		return 0;
	}

	fscanf(fi, "%d\n", &n);

	for (int i = 1; i <= n; i++)
	{
		fscanf(fi, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#%d#", x.MX, x.BSX, x.LX
			, x.TenChuXe, &x.gioVao.ngay
			, &x.gioVao.thang, &x.gioVao.nam
			, &x.gioVao.gio, &x.gioVao.phut);
		fscanf(fi, "%d#%d#%d#%d#%d#%d\n", &x.gioRa.ngay, &x.gioRa.thang, &x.gioRa.nam
			, &x.gioRa.gio, &x.gioRa.phut, &x.giaGui);
		SNode*p = createSNode(x);
		if (p == NULL)
		{
			printf("LOI!");
			return 0;
		}

		insertTail(dsRa, p);
	}

	fclose(fi);
	return 1;
}

int themVaoDsLuotXeVaoGanNhat(Stack& st, Itemtype x)
{
	StackNode* p = createStackNode(x);
	if (p == NULL)
		return 0;

	else
	{
		PUSH(st, p);
	}

	return 1;
}

int themVaoDsLuotXeRaGanNhat(Stack& st, Itemtype x)
{
	StackNode* p = createStackNode(x);
	if (p == NULL)
		return 0;

	else
	{
		PUSH(st, p);
	}

	return 1;
}

int demSoChoConLai(SList dsVao){
	//Đếm số chỗ còn lại trong bãi
	system("cls");
	int demTongCho = countAllXeTrongBai(dsVao);
	int soChoConLai = MaxCho - demTongCho;
	return soChoConLai;
}

// in danh sach

void show1XeVao(Itemtype x)
{
	printf("%-10s%-15s%-15s%-15s", x.MX, x.BSX, x.LX, x.TenChuXe);
	printf("%2d:%2d ", x.gioVao.gio, x.gioVao.phut);
	printf("%2d/%2d/%4d\n", x.gioVao.ngay, x.gioVao.thang, x.gioVao.nam);
}

void show1XeRa(Itemtype x)
{
	printf("%-10s%-15s%-15s%-15s", x.MX, x.BSX, x.LX, x.TenChuXe);
	printf("%2d:%2d ", x.gioVao.gio, x.gioVao.phut);
	printf("%2d/%2d/%4d\t\t", x.gioVao.ngay, x.gioVao.thang, x.gioVao.nam);

	printf("%2d:%2d ", x.gioRa.gio, x.gioRa.phut);
	printf("%2d/%2d/%4d ", x.gioRa.ngay, x.gioRa.thang, x.gioRa.nam);
	printf("%20d\n", x.giaGui);
}

void inDSXeVao(SList dsVao)
{
	printf("%-10s%-15s%-15s%-18s%-20s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO");
	if (isEmpty(dsVao) == 1)
		printf("Danh sach rong!\n");

	for (SNode* p = dsVao.Head; p != NULL; p = p->Next)
	{
		show1XeVao(p->Info);
	}
}

void inDSXeRa(SList dsRa)
{
	printf("%-10s%-15s%-15s%-18s%-26s%-18s%15s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO", "THOI GIAN RA", "SO TIEN GUI");
	if (isEmpty(dsRa) == 1)
		printf("Danh sach rong!\n");

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		show1XeRa(p->Info);
	}
}

void inDsXeVaoGanNhat(Stack st)
{
	printf("%-10s%-15s%-15s%-18s%-20s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO");
	if (isEmptyStack(st) == 1)
		printf("CHUA CO XE NAO VAO.\n");
	else
	{
		for (StackNode* p = st.Top; p != NULL; p = p->Next)
		{
			show1XeVao(p->Info);
		}
	}

}

void inDsXeRaGanNhat(Stack st)
{
	printf("%-10s%-15s%-15s%-18s%-26s%-18s%15s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO", "THOI GIAN RA", "SO TIEN GUI");
	if (isEmptyStack(st) == 1)
		printf("CHUA CO XE NAO RA.\n");
	else
	{
		for (StackNode* p = st.Top; p != NULL; p = p->Next)
		{
			show1XeRa(p->Info);
		}
	}

}

// Tim kiem

SNode* findsTheoBienSoXe(SList dsVao, Itemtype x)
{
	if (isEmpty(dsVao) == 1)
		return NULL;

	SNode* p = dsVao.Head;

	while (p != NULL)
	{
		if (strcmpi(p->Info.BSX, x.BSX) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

SNode* findsTheoMaXe(SList dsVao, Itemtype x)
{
	if (isEmpty(dsVao) == 1)
		return NULL;

	SNode* p = dsVao.Head;

	while (p != NULL)
	{
		if (strcmpi(p->Info.MX, x.MX) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

SNode* findsTheoTenChuXe(SList dsVao, Itemtype x)
{
	if (isEmpty(dsVao) == 1)
		return NULL;

	SNode* p = dsVao.Head;

	while (p != NULL)
	{
		if (strcmpi(p->Info.TenChuXe, x.TenChuXe) == 0)
			return p;
		p = p->Next;
	}
	return NULL;
}

void timKiemTheoBienSoXe(SList dsVao, SList dsRa)
{
	Itemtype x;
	int ktra = 0;

	printf("Nhap bien so xe: ");
	rewind(stdin);
	gets_s(x.BSX);

	int timKiem;
	printf("1: HIEN TAI TRONG BAI.\n2: TRONG LICH SU.\nBAN MUON TIM KIEM TRONG DS NAO:");
	scanf("%d", &timKiem);

	if (timKiem == 1)
	{
		if (isEmpty(dsVao) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}

		SNode* p = dsVao.Head; // tìm kiếm trong bãi
		printf("DANH SACH XE TRONG BAI.\n");

		while (p != NULL)
		{
			if (strcmpi(p->Info.BSX, x.BSX) == 0)
			{
				show1XeVao(p->Info);
				ktra = 1;
			}
			p = p->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	else
	{
		if (isEmpty(dsRa) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}

		SNode* q = dsRa.Head; // tìm kiếm trong lịch sử
		printf("DANH SACH XE ROI BAI\n");

		while (q != NULL)
		{
			if (strcmpi(q->Info.BSX, x.BSX) == 0)
			{
				show1XeRa(q->Info);
				ktra = 1;
			}
			q = q->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	return;
}

void timKiemTheoMaXe(SList dsVao, SList dsRa)
{
	Itemtype x;
	int ktra = 0;

	printf("Nhap ma xe: ");
	rewind(stdin);
	gets_s(x.MX);

	int timKiem;
	printf("1: HIEN TAI TRONG BAI.\n2: TRONG LICH SU.\nBAN MUON TIM KIEM TRONG DS NAO:");
	scanf("%d", &timKiem);

	if (timKiem == 1)
	{
		if (isEmpty(dsVao) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}
		SNode* p = dsVao.Head; // tìm kiếm trong bãi
		printf("DANH SACH XE TRONG BAI.\n");

		while (p != NULL)
		{
			if (strcmpi(p->Info.MX, x.MX) == 0)
			{
				show1XeVao(p->Info);
				ktra = 1;
			}
			p = p->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	else
	{
		if (isEmpty(dsRa) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}
		SNode* q = dsRa.Head; // tìm kiếm trong lịch sử
		printf("DANH SACH XE ROI BAI\n");

		while (q != NULL)
		{
			if (strcmpi(q->Info.MX, x.MX) == 0)
			{
				show1XeRa(q->Info);
				ktra = 1;
			}
			q = q->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	return;
}

void timKiemTheoTenChuXe(SList dsVao, SList dsRa)
{
	Itemtype x;
	int ktra = 0;

	printf("Nhap ten chu xe: ");
	rewind(stdin);
	gets_s(x.TenChuXe);



	int timKiem;
	printf("1: HIEN TAI TRONG BAI.\n2: TRONG LICH SU.\nBAN MUON TIM KIEM TRONG DS NAO:");
	scanf("%d", &timKiem);

	if (timKiem == 1)
	{
		if (isEmpty(dsVao) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}
		SNode* p = dsVao.Head; // tìm kiếm trong bãi
		printf("DANH SACH XE TRONG BAI.\n");

		while (p != NULL)
		{
			if (strcmpi(p->Info.TenChuXe, x.TenChuXe) == 0)
			{
				show1XeVao(p->Info);
				ktra = 1;
			}
			p = p->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	else
	{
		if (isEmpty(dsRa) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}
		SNode* q = dsRa.Head; // tìm kiếm trong lịch sử
		printf("DANH SACH XE ROI BAI\n");

		while (q != NULL)
		{
			if (strcmpi(q->Info.TenChuXe, x.TenChuXe) == 0)
			{
				show1XeRa(q->Info);
				ktra = 1;
			}
			q = q->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	return;
}

void timKiemTheoLoaiXe(SList dsVao, SList dsRa)
{
	Itemtype x;
	int ktra = 0;

	printf("Nhap loai xe: ");
	rewind(stdin);
	gets_s(x.LX);

	int timKiem;
	printf("1: HIEN TAI TRONG BAI.\n2: TRONG LICH SU.\nBAN MUON TIM KIEM TRONG DS NAO:");
	scanf("%d", &timKiem);

	if (timKiem == 1)
	{
		if (isEmpty(dsVao) == 1)
		{
			printf("Khong tim thay!\n");
			return;
		}
		SNode* p = dsVao.Head; // tìm kiếm trong bãi
		printf("DANH SACH XE TRONG BAI.\n");

		while (p != NULL)
		{
			if (strcmpi(p->Info.LX, x.LX) == 0)
			{
				show1XeVao(p->Info);
				ktra = 1;
			}
			p = p->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	else
	{
		SNode* q = dsRa.Head; // tìm kiếm trong lịch sử
		printf("DANH SACH XE ROI BAI\n");

		while (q != NULL)
		{
			if (isEmpty(dsRa) == 1)
			{
				printf("Khong tim thay!\n");
				return;
			}
			if (strcmpi(q->Info.LX, x.LX) == 0)
			{
				show1XeRa(q->Info);
				ktra = 1;
			}
			q = q->Next;
		}

		if (ktra == 0)
			printf("Khong tim thay!\n");
	}

	return;
}

// Thêm xe vào bãi

int themXeVaoBai(SList& dsVao, Itemtype& x, Stack& dsVaoGN)
{
	nhap1Xe(x);
	SNode*p = createSNode(x);
	if (!p)
		return 0;

	SNode* q = findsTheoMaXe(dsVao, x); // kiểm tra mã, không được trùng trong ds
	if (q == NULL)
	{
		if (demSoChoConLai(dsVao) == 0)
		{
			printf("BAI XE DA DAY.\n");
			return 0;
		}

		else if (demSoChoConLai(dsVao) < 6)
		{
			int choConLai = demSoChoConLai(dsVao) - 1;
			printf("BAI XE CON %d CHO\n", choConLai);
			insertTail(dsVao, p);
			themVaoDsLuotXeVaoGanNhat(dsVaoGN, x);
			saveVaoDsXeVaoBai(dsVao, "xeVaoBai.txt");
			return 1;
		}
		else
		{
			insertTail(dsVao, p);
			themVaoDsLuotXeVaoGanNhat(dsVaoGN, x);
			saveVaoDsXeVaoBai(dsVao, "xeVaoBai.txt");
			return 1;
		}
	}
	return 0;
}

// tính tiền

int tinhGioGuiXe(date vao, date ra)
{
	int tongGio = 0;
	int ngayChenhLech = 0;

	// kiểm tra phút
	if (vao.phut < ra.phut)
		tongGio += 1;

	// kiểm tra ngày

	// Nếu cùng ngày cùng tháng cùng năm
	if (vao.ngay == ra.ngay && vao.thang == ra.thang && vao.nam == ra.nam)
	{
		tongGio += ra.gio - vao.gio;
	}

	// Nếu khác ngày cùng tháng cùng năm
	else if (vao.ngay != ra.ngay && vao.thang == ra.thang && vao.nam == ra.nam)
	{
		tongGio = 24 - vao.gio; // Tính hết giờ đến hết ngày gửi

		// Ngày chênh lệch (bỏ ngày vào và ngày ra) nhân cho 24 giờ
		ngayChenhLech = ra.ngay - vao.ngay - 1;
		tongGio += ngayChenhLech * 24;

		// Tính giờ ngày lấy xe ra
		tongGio += ra.gio;
	}

	// Nếu khác ngày khác tháng cùng năm
	else if (vao.ngay != ra.ngay && vao.thang != ra.thang && vao.nam == ra.nam)
	{
		tongGio = 24 - vao.gio; // Tính giờ đến hết ngày gửi
		for (int thang = vao.thang + 1; thang < ra.thang; thang++)
		{
			tongGio += soNgayTrongThang(thang, vao.nam) * 24; // Tính giờ đến chênh lệch tháng
		}
		tongGio += (soNgayTrongThang(vao.thang, vao.nam) - vao.ngay) * 24; // Tính giờ của những ngày còn lại trong tháng vào
		tongGio += (ra.ngay - 1) * 24; // Tính giờ đến ngày trước ngày lấy
		tongGio += ra.gio; //Tính giờ ngày lấy xe
	}

	// Nếu khác ngày khác tháng khác năm
	else if (vao.ngay != ra.ngay && vao.thang != ra.thang && vao.nam != ra.nam)
	{
		tongGio = 24 - vao.gio; // Tính giờ đến hết ngày gửi
		tongGio += (soNgayTrongThang(vao.thang, vao.nam) - vao.ngay) * 24; // Tính giờ đến hết tháng

		// Tính giờ của các tháng còn lại trong năm vào
		for (int thang = vao.thang + 1; thang <= 12; thang++)
		{
			tongGio += soNgayTrongThang(thang, vao.nam) * 24;
		}

		// Tính giờ của các năm trọn vẹn ở giữa
		for (int nam = vao.nam + 1; nam < ra.nam; nam++)
		{
			tongGio += (namNhuan(nam) ? 366 : 365) * 24;
		}

		// Tính giờ của các tháng đã qua trong năm ra
		for (int thang = 1; thang < ra.thang; thang++)
		{
			tongGio += soNgayTrongThang(thang, ra.nam) * 24;
		}

		tongGio += (ra.ngay - 1) * 24; // Tính giờ đến ngày trước ngày lấy
		tongGio += ra.gio; //Tính giờ ngày lấy xe
	}

	// Nếu cùng ngày khác tháng cùng năm
	else if (vao.ngay == ra.ngay && vao.thang != ra.thang && vao.nam == ra.nam)
	{
		tongGio = 24 - vao.gio; // Tính giờ đến hết ngày gửi
		tongGio += (soNgayTrongThang(vao.thang, vao.nam) - vao.ngay) * 24; // Tính giờ đến hết tháng

		// Tính giờ của các tháng trọn vẹn ở giữa
		for (int thang = vao.thang + 1; thang < ra.thang; thang++)
		{
			tongGio += soNgayTrongThang(thang, vao.nam) * 24;
		}

		tongGio += ra.gio; //Tính giờ ngày lấy xe
	}

	// Nếu cùng ngày cùng tháng khác năm
	else if (vao.ngay == ra.ngay && vao.thang == ra.thang && vao.nam != ra.nam)
	{
		int namBatDau = vao.nam;
		int namKetThuc = ra.nam;

		// Tính số giờ của các năm trọn vẹn ở giữa
		for (int nam = namBatDau; nam < namKetThuc; nam++)
		{
			tongGio += (namNhuan(nam) ? 366 : 365) * 24;
		}

		tongGio += ra.gio - vao.gio; // cộng thêm sự chêch lệch giờ trong ngày
	}

	// Nếu khác ngày cùng tháng khác năm
	else if (vao.ngay != ra.ngay && vao.thang == ra.thang && vao.nam != ra.nam)
	{
		// Xác định năm bắt đầu và năm kết thúc
		int namBatDau = vao.nam;
		int namKetThuc = ra.nam;

		// Tính giờ còn lại của ngày vào trong năm vào
		tongGio += (soNgayTrongThang(vao.thang, vao.nam) - vao.ngay) * 24 + (24 - vao.gio);

		// Tính giờ của các năm trọn vẹn ở giữa
		for (int nam = namBatDau + 1; nam < namKetThuc; nam++)
		{
			tongGio += (namNhuan(nam) ? 366 : 365) * 24;
		}

		// Tính giờ từ đầu năm ra đến ngày ra
		tongGio += (ra.ngay - 1) * 24 + ra.gio;
	}

	// Nếu cùng ngày khác tháng khác năm
	else if (vao.ngay == ra.ngay && vao.thang != ra.thang && vao.nam != ra.nam)
	{
		tongGio = 24 - vao.gio; // Tính giờ đến hết ngày gửi

		// Tính số ngày còn lại trong tháng
		ngayChenhLech = soNgayTrongThang(vao.thang, vao.nam) - vao.ngay;

		// Tính giờ của các tháng còn lại trong năm vào
		for (int thang = vao.thang + 1; thang <= 12; thang++)
		{
			tongGio += soNgayTrongThang(thang, vao.nam) * 24;
		}

		// Tính giờ của các năm trọn vẹn ở giữa
		for (int nam = vao.nam + 1; nam < ra.nam; nam++)
		{
			for (int thang = 1; thang <= 12; thang++)
			{
				tongGio += soNgayTrongThang(thang, nam) * 24;
			}
		}

		// Tính giờ từ đầu năm ra đến tháng ra (trừ tháng ra)
		for (int thang = 1; thang < ra.thang; thang++)
		{
			tongGio += soNgayTrongThang(thang, ra.nam) * 24;
		}

		// Cộng thêm giờ trong ngày ra
		tongGio += ra.gio;
	}
	return tongGio;
}

int kiemTraGioQuyDinh(date vao, date ra)
{
	if (ra.gio >= 8 && ra.gio < 22 && vao.ngay == ra.ngay)
		return 1; // đúng quy định

	return 0; // sai quy định
}

void timNgayHomSau(int& ngay, int& thang, int& nam)
{
	ngay++;
	if (ngay > soNgayTrongThang(thang, nam))
	{
		ngay = 1;
		thang++;
		if (thang > 12)
		{
			thang = 1;
			nam++;
		}
	}
}

int kiemTraPhat(Itemtype x)
{
	// Tìm ngày hôm sau
	date ngayHomSauVao = x.gioVao;
	timNgayHomSau(ngayHomSauVao.ngay, ngayHomSauVao.thang, ngayHomSauVao.nam);


	// Phạt nếu có vé nhưng ra sau 6h sáng hôm sau
	if (x.veXemPhim == 1 && x.gioRa.gio > 6 &&
		x.gioRa.ngay == ngayHomSauVao.ngay && x.gioRa.thang == ngayHomSauVao.thang
		&& x.gioRa.nam == ngayHomSauVao.nam)

		return 1; // Phạt

	// Không phạt nếu có vé và về trước 6h sáng hôm sau
	if ((x.veXemPhim == 1 &&
		(x.gioRa.gio < 6 && x.gioRa.ngay == ngayHomSauVao.ngay && x.gioRa.thang == ngayHomSauVao.thang
		&& x.gioRa.nam == ngayHomSauVao.nam)) || (x.veXemPhim == 1 &&
		(x.gioVao.ngay == x.gioRa.ngay && x.gioVao.thang == x.gioRa.thang && x.gioVao.nam == x.gioRa.nam)))
	{
		return 0; // Không phạt
	}

	return 1;
}

void nhapVeXemPhim(Itemtype &x)
{
	printf("1: CO\n2: KHONG\n");
	printf("KIEM TRA VE XEM PHIM: ");
	scanf("%d", &x.veXemPhim);
}

int tinhTienXeOto(Itemtype x)
{
	// Tính tiền oto theo ca 4 tiếng: 35k/ca.
	int ca = 1;
	int gioGuiXe = tinhGioGuiXe(x.gioVao, x.gioRa);

	if (gioGuiXe > 0)
	{
		ca = gioGuiXe / 4; // 1 ca 4 tiếng

		if (gioGuiXe % 4 > 0) // nếu hơn 4 tiếng là tính ca tiếp theo
			ca += 1;
	}

	int tongTienGui = ca * 35000; // thành tiền

	if (kiemTraGioQuyDinh(x.gioVao, x.gioRa) == 0)
	{
		nhapVeXemPhim(x);
		if (kiemTraPhat(x) == 1)
			tongTienGui += 450000;
	}

	return tongTienGui;
}

int tinhTienXeMay(Itemtype x)
{
	// 4h đầu tiên là 4k nếu lố thì cộng thêm mỗi giờ 1k
	int tongTienGui = 4000;

	int tongGioGui = tinhGioGuiXe(x.gioVao, x.gioRa);
	if (tongGioGui > 4)
	{
		tongTienGui = 4000 + (tongGioGui - 4) * 1000;
	}

	if (kiemTraGioQuyDinh(x.gioVao, x.gioRa) == 0)
	{
		nhapVeXemPhim(x);
		if (kiemTraPhat(x) == 1)
			tongTienGui += 250000;
	}

	return tongTienGui;
}

int tinhTienXeDap(Itemtype x)
{
	return 2000;
}

int tinhTienGuiXe(Itemtype x)
{
	int tongTien = 0;
	if (strcmpi(x.LX, "oto") == 0)
		tongTien = tinhTienXeOto(x);

	else if (strcmpi(x.LX, "xe may") == 0)
		tongTien = tinhTienXeMay(x);

	else if (strcmpi(x.LX, "xe dap") == 0)
		tongTien = tinhTienXeDap(x);

	return tongTien;
}

int tinhTienTuNgayDenNgay(SList dsRa, int ngayBatDau, int thangBatDau, int namBatDau, int ngayKetThuc, int thangKetThuc, int namKetThuc) {
	int tongTien = 0;

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next) {
		// Kiểm tra nếu ngày ra của xe nằm trong khoảng từ ngày bắt đầu đến ngày kết thúc
		if ((p->Info.gioRa.nam > namBatDau || (p->Info.gioRa.nam == namBatDau && p->Info.gioRa.thang > thangBatDau) || (p->Info.gioRa.nam == namBatDau && p->Info.gioRa.thang == thangBatDau && p->Info.gioRa.ngay >= ngayBatDau)) &&
			(p->Info.gioRa.nam < namKetThuc || (p->Info.gioRa.nam == namKetThuc && p->Info.gioRa.thang < thangKetThuc) || (p->Info.gioRa.nam == namKetThuc && p->Info.gioRa.thang == thangKetThuc && p->Info.gioRa.ngay <= ngayKetThuc)))
			tongTien += tinhTienGuiXe(p->Info);
	}

	return tongTien;
}

// Xoa xe khoi bai

int xeRoiBai_TheoBienSo(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN)
{
	printf("Nhap bien so xe: ");
	rewind(stdin);
	gets_s(x.BSX);


	SNode* q = findsTheoBienSoXe(dsVao, x);
	if (q == NULL)
		return 0;

	else
	{
		printf("%-10s%-15s%-15s%-18s%-20s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO");
		show1XeVao(q->Info);
	}


	x = q->Info; //lưu lại trước khi xóa

	if (q == dsVao.Head)
	{
		deleteHead(dsVao, x);
	}

	else if (q == dsVao.Tail)
	{
		deleteTail(dsVao, x);
	}

	else
	{
		SNode* p = q->Next;
		deleteAfter(dsVao, x, p);
	}

	int chon;

	do
	{
		printf("\n1: TU DONG\n");
		printf("2: NHAP THU CONG\n");
		printf("BAN MUON NHAP THOI GIAN TU DONG HAY THU CONG: ");
		scanf("%d", &chon);

		if (chon != 1 && chon != 2)
			printf("VUI LONG NHAP LAI!\n");

	} while (chon != 1 && chon != 2);

	switch (chon)
	{
	case 1:
	{
			  timeAuto(&x.gioRa.gio, &x.gioRa.phut, &x.gioRa.ngay, &x.gioRa.thang, &x.gioRa.nam);
			  break;
	}

	case 2:
	{
			  nhapThoiGianRa(x);
			  break;
	}
	default:
		printf("KHONG CO CHUC NANG NAY.\n");
		break;
	}

	x.giaGui = tinhTienGuiXe(x);
	SNode* p = createSNode(x);
	insertTail(dsRa, p);
	themVaoDsLuotXeRaGanNhat(dsRaGN, x);

	system("cls");
	printf("PHI GUI XE: %d\n", x.giaGui);
	printf("THU THANH CONG NHAN ENTER\n");
	getch();

	saveVaoDsXeVaoBai(dsVao, "xeVaoBai.txt");
	saveVaoDsXeRaBai(dsRa, "lichSuXeTrongBai.txt");
	return 1;
}

int xeRoiBai_TheoMaXe(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN)
{
	printf("Nhap ma xe: ");
	rewind(stdin);
	gets_s(x.MX);


	SNode* q = findsTheoMaXe(dsVao, x);

	if (q == NULL)
		return 0;

	else
	{
		printf("%-10s%-15s%-15s%-18s%-20s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO");
		show1XeVao(q->Info);
	}

	x = q->Info; //lưu lại trước khi xóa

	if (q == dsVao.Head)
	{
		deleteHead(dsVao, x);
	}

	else if (q == dsVao.Tail)
	{
		deleteTail(dsVao, x);
	}

	else
	{
		SNode* p = q->Next;
		deleteAfter(dsVao, x, p);
	}

	int chon;
	do
	{
		printf("\n1: TU DONG\n");
		printf("2: NHAP THU CONG\n");
		printf("BAN MUON NHAP THOI GIAN TU DONG HAY THU CONG: ");
		scanf("%d", &chon);

		if (chon != 1 && chon != 2)
			printf("VUI LONG NHAP LAI!\n");

	} while (chon != 1 && chon != 2);


	switch (chon)
	{
	case 1:
	{
			  timeAuto(&x.gioRa.gio, &x.gioRa.phut, &x.gioRa.ngay, &x.gioRa.thang, &x.gioRa.nam);
			  break;
	}

	case 2:
	{
			  nhapThoiGianRa(x);
			  break;
	}
	default:
		printf("KHONG CO CHUC NANG NAY.\n");
		break;
	}

	x.giaGui = tinhTienGuiXe(x);
	SNode* p = createSNode(x);
	insertTail(dsRa, p);
	themVaoDsLuotXeRaGanNhat(dsRaGN, x);

	system("cls");
	printf("PHI GUI XE: %d\n", x.giaGui);
	printf("THU THANH CONG NHAN ENTER\n");
	getch();

	saveVaoDsXeVaoBai(dsVao, "xeVaoBai.txt");
	saveVaoDsXeRaBai(dsRa, "lichSuXeTrongBai.txt");

	return 1;
}

// Nhan Vien

int kiemTraQuanLi(nhanVien nv)
{
	if (strcmpi(nv.chucVu, "quan li") == 0)
		return 1;

	return 0;
}

int kiemTraDangNhap(nhanVien nv, SListNV dsnv)
{
	for (SNodeNV* p = dsnv.Head; p != NULL; p = p->Next)
	{
		if (strcmp(nv.matKhau, p->Info.matKhau) == 0 && strcmpi(nv.maNV, p->Info.maNV) == 0)
			return 1;
	}
	printf("THONG TIN DANG NHAP KHONG DUNG\n");
	return 0;
}

// Loi chao

void banQuyen()
{
	printf("    **********      **********       ****       **********     **********       ****       **********\n");
	Sleep(10);
	printf("  *            *    ***********    ********     **********     ***********    ********     **********\n");
	Sleep(10);
	printf(" *    ******    *   **       **   **********    ***    ***     **       **   **********    ***    ***\n");
	Sleep(10);
	printf("*    *           *  **       **  ****    ****   ***    ***     **       **  ****    ****   ***    ***\n");
	Sleep(10);
	printf("*    *           *  ***********  ****    ****   ***    *** * * ***********  ****    ****   ***    ***\n");
	Sleep(10);
	printf("*    *           *  ***********  ************   ***    ***  *  ***********  ************   ***    ***\n");
	printf("*    *           *  **       **  ************   ***    *** * * **       **  ************   ***    ***\n");
	printf(" *    ******    *   **       **  ****    ****   ***    ***     **       **  ****    ****   ***    ***\n");
	printf("  *            *    ***********  ****    ****   **********     ***********  ****    ****   **********\n");
	printf("    ***********     **********   ****    ****   **********     **********   ****    ****   **********\n");
	printf("\n\n\t\t\tBAN QUYEN THUOC VE TRAN GIA BAO & TRAN DUONG GIA BAO\n");
	Sleep(3500);
	//	system("cls");
}

void veHinhTraiTim()
{
	float x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.2f) {
		printf("\t\t");
		Sleep(50);
		for (x = -1.5f; x < 1.5f; x += 0.1f) {
			float a = x * x + y * y - 1;
			if ((a * a * a - x * x * y * y * y) <= 0.0f)
			{
				printf("*");
			}

			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\t\t~~~~ DANG XUAT THANH CONG ~~~~\n");
	Sleep(2000);
	return;
}

void load()
{
	printf("***          **********       ****       *******\n");
	printf("***          **********     ********     ********\n");
	printf("***          ***    ***    **********    ***    ** \n");
	printf("***          ***    ***   ****    ****   ***    ***\n");
	printf("***          ***    ***   ****    ****   ***    ***\n");
	printf("***          ***    ***   ************   ***    ***\n");
	printf("***          ***    ***   ************   ***    ***\n");
	printf("***          ***    ***   ****    ****   ***    ** \n");
	printf("**********   **********   ****    ****   ******** \n");
	printf("**********   **********   ****    ****   ******* \n");

}

void loiChao()
{
	printf("*****     ******   ***********   ***          ***          **********\n");
	Sleep(100);
	printf("*****     ******   ***********   ***          ***          **********\n");
	Sleep(100);
	printf("*****     ******   ***	         ***          ***          ***    ***\n");
	Sleep(100);
	printf("*****     ******   ***	         ***          ***          ***    ***\n");
	Sleep(100);
	printf("****************   ***********   ***          ***          ***    ***\n");
	Sleep(100);
	printf("****************   ***********   ***          ***          ***    ***\n");
	Sleep(100);
	printf("*****     ******   ***           ***          ***          ***    ***\n");
	Sleep(100);
	printf("*****     ******   ***           ***          ***          ***    ***\n");
	Sleep(100);
	printf("*****     ******   ***********   **********   **********   **********\n");
	Sleep(100);
	printf("*****     ******   ***********   **********   **********   **********\n");

}

int dangNhap(NV& nv, SListNV dsnv)
{

	int dem = 0;

	int ktraDangNhap = 0;
	system("cls");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("               -------- DANG NHAP --------            \n");

	do
	{
		dem++;

		printf("NHAP MA NHAN VIEN: ");
		rewind(stdin);
		gets_s(nv.maNV);

		printf("NHAP MAT KHAU: ");
		rewind(stdin);
		gets_s(nv.matKhau);

		ktraDangNhap = kiemTraDangNhap(nv, dsnv);


		if (dem >= 3)
			printf("\nVUI LONG LIEN HE QUAN LY DE DUOC CAP LAI MAT KHAU.\n\n");

	} while (ktraDangNhap == 0);

	SNodeNV* p = findSNode_TheoMSNV(dsnv, nv);
	nv = p->Info;

	return 1;
}

// Các chức năng

void MENUChuongTrinh(NV user)
{

	system("cls");
	load();
	Sleep(500);

	int ktraQuanLi = kiemTraQuanLi(user);

	system("cls");

	int i = 0;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\t\t\tXIN CHAO, %s\n", user.tenNV);
	printf("*            ----- MENU QUAN LY BAI XE -----         *"); printf("\t\t\tCHUC VU: %s\n", user.chucVu);
	printf("* 0%d. DANG XUAT                                      *\n", i); i++;
	printf("* 0%d. THEM XE VAO BAI                                *\n", i); i++;
	printf("* 0%d. XE ROI BAI                                     *\n", i); i++;
	printf("* 0%d. TIM KIEM XE                                    *\n", i); i++;
	printf("* 0%d. THONG KE                                       *\n", i); i++;
	printf("* 0%d. CANH BAO XE DA GUI QUA 24H                     *\n", i); i++;
	if (ktraQuanLi == 1)
		printf("* 0%d. QUAN LI NHAN VIEN                              *\n", i); i++;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void MENUChucNang1(NV user)
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\t\t\tXIN CHAO, %s\n", user.tenNV);
	printf("*              ---- THEM XE VAO BAI ----             *"); printf("\t\t\tCHUC VU: %s\n", user.chucVu);
	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. THEM XE VAO BAI                                *\n", i); i++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void chucNang1A(SList& dsVao, Itemtype& x, Stack& st)
{
	system("cls");
	printf("NHAP THONG TIN XE VAO BAI:\n");
	int kq;

	do
	{
		kq = themXeVaoBai(dsVao, x, st);
		if (kq == 0)
			printf("MA XE BI TRUNG!\n");

	} while (kq == 0);

	printf("DA THEM THANH CONG\n");
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void MENUChucNang2(NV user)
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\t\t\tXIN CHAO, %s\n", user.tenNV);
	printf("*                 ---- XE ROI BAI ----               *"); printf("\t\t\tCHUC VU: %s\n", user.chucVu);
	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. XE ROI BAI THEO MA                             *\n", i); i++;
	printf("* 0%d. XE ROI BAI THEO BIEN SO                        *\n", i); i++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void chucNang2A(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN)
{
	system("cls");
	printf("NHAP THONG TIN XE ROI BAI:\n");
	int kq = xeRoiBai_TheoMaXe(dsVao, dsRa, x, dsRaGN);

	if (kq == 1)
	{
		printf("XE ROI BAI THANH CONG!\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
	}

	else
	{
		printf("KHONG TIM THAY MA XE TRONG BAI!.\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
	}

}

void chucNang2B(SList& dsVao, SList& dsRa, Itemtype& x, Stack& st)
{
	system("cls");
	printf("NHAP THONG TIN XE ROI BAI:\n");
	int kq = xeRoiBai_TheoBienSo(dsVao, dsRa, x, st);

	if (kq == 1)
	{
		printf("XE ROI BAI THANH CONG!\n");
		getch();
	}

	else
	{
		printf("KHONG TIM THAY BIEN SO XE TRONG BAI!.\n");
		getch();
	}

}

void MENUChucNang3(NV user)
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\t\t\tXIN CHAO, %s\n", user.tenNV);
	printf("*                ---- TIM KIEM XE ----               *"); printf("\t\t\tCHUC VU: %s\n", user.chucVu);
	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. TIM KIEM XE THEO MA                            *\n", i); i++;
	printf("* 0%d. TIM KIEM XE THEO BIEN SO XE                    *\n", i); i++;
	printf("* 0%d. TIM KIEM XE THEO TEN CHU XE                    *\n", i); i++;
	printf("* 0%d. TIM KIEM XE THEO LOAI XE                       *\n", i); i++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void chucNang3A(SList dsVao, SList dsRa)
{
	system("cls");
	printf("NHAP THONG TIN XE CAN TIM:\n");
	timKiemTheoMaXe(dsVao, dsRa);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang3B(SList dsVao, SList dsRa)
{
	system("cls");
	printf("NHAP THONG TIN XE CAN TIM:\n");
	timKiemTheoBienSoXe(dsVao, dsRa);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();

}

void chucNang3C(SList dsVao, SList dsRa)
{
	system("cls");

	printf("NHAP THONG TIN XE CAN TIM:\n");
	timKiemTheoTenChuXe(dsVao, dsRa);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();

}

void chucNang3D(SList dsVao, SList dsRa)
{
	system("cls");

	printf("NHAP THONG TIN XE CAN TIM:\n");
	timKiemTheoLoaiXe(dsVao, dsRa);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();

}

void MENUChucNang4(NV user)
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("\t\t\tXIN CHAO, %s\n", user.tenNV);
	printf("*                 ---- THONG KE ----                 *"); printf("\t\t\tCHUC VU: %s\n", user.chucVu);

	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. DEM TONG SO LUONG XE TRONG BAI                 *\n", i); i++;
	printf("* 0%d. DEM SO CHO CON LAI TRONG BAI                   *\n", i); i++;
	printf("* 0%d. DEM SO LUONG XE THEO LOAI TRONG BAI            *\n", i); i++;
	printf("* 0%d. DEM LOAI XE NHIEU NHAT TRONG BAI               *\n", i); i++;
	printf("* 0%d. TINH TONG TIEN XE TRONG NGAY                   *\n", i); i++;
	printf("* 0%d. TINH TONG TIEN XE TRONG THANG                  *\n", i); i++;
	printf("* 0%d. TINH TONG TIEN XE TRONG NAM                    *\n", i); i++;
	printf("* 0%d. TINH TONG TIEN XE TU NGAY DEN NGAY             *\n", i); i++;
	printf("* 0%d. IN DANH SACH XE TRONG BAI                      *\n", i); i++;
	printf("* %d. IN DANH SACH XE TRONG BAI SAP XEP THEO GIO     *\n", i); i++;
	printf("* %d. IN DANH SACH LICH SU XE TRONG BAI              *\n", i); i++;
	printf("* %d. IN DANH SACH LICH SU THEO NGAY RA              *\n", i); i++;
	printf("* %d. IN DANH SACH LICH SU THEO THANG RA             *\n", i); i++;
	printf("* %d. IN DANH SACH LICH SU THEO NAM RA               *\n", i); i++;
	printf("* %d. IN DANH SACH LUOT XE VAO GAN NHAT              *\n", i); i++;
	printf("* %d. IN DANH SACH LUOT XE RA GAN NHAT               *\n", i); i++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void chucNang4A(SList dsVao)
{
	// Đếm toàn bộ xe trong bãi
	system("cls");
	int dem = countAllXeTrongBai(dsVao);
	printf("TONG SO XE TRONG BAI LA %d\n", dem);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4AA(SList dsVao)
{
	int soChoConLai = demSoChoConLai(dsVao);
	printf("SO CHO CON LAI TRONG BAI: %d cho\n", soChoConLai);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4B(SList dsVao)
{
	// Đếm xe theo loại
	system("cls");

	int demXeMay = countXeTheoLoai(dsVao, "XE MAY");
	int demOTO = countXeTheoLoai(dsVao, "OTO");
	int demXeDap = countXeTheoLoai(dsVao, "XE DAP");

	printf("TONG SO XE MAY TRONG BAI LA %d\n", demXeMay);
	printf("TONG SO XE OTO TRONG BAI LA %d\n", demOTO);
	printf("TONG SO XE DAP TRONG BAI LA %d\n", demXeDap);

	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4C(SList dsVao)
{
	// Đếm xe nhiều nhất trong bãi theo 
	system("cls");
	int dem = countLoaiXeNhieuNhatTrongBai(dsVao);
	if (dem == 0)
		printf("KHONG CO XE NAO TRONG BAI!.\n");
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4D(SList dsRa)
{
	// tính tổng tiền theo ngày.
	system("cls");
	int ngay, thang, nam;
	nhapNgayThangNam(ngay, thang, nam);

	int tongTien = 0;
	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.ngay == ngay && p->Info.gioRa.thang == thang && p->Info.gioRa.nam == nam)
		{
			tongTien += p->Info.giaGui;
		}
	}
	printf("Tong tien cua ngay %d/%d/%d la: %d\n", ngay, thang, nam, tongTien);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4E(SList dsRa)
{
	// tính tổng tiền theo tháng.
	system("cls");
	int thang, nam;
	do
	{
		printf("Nhap thang: ");
		scanf("%d", &thang);

		printf("Nhap nam: ");
		scanf("%d", &nam);

		if (thang > 12 && thang < 1)
			printf("Vui long xem lai!\n");

	} while (thang > 12 && thang < 1);

	int tongTien = 0;
	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.thang == thang && p->Info.gioRa.nam == nam)
		{
			tongTien += p->Info.giaGui;
		}
	}
	printf("Tong tien cua thang %d/%d la: %d\n", thang, nam, tongTien);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4F(SList dsRa)
{
	// tính tổng tiền theo năm.
	system("cls");
	int nam;

	printf("Nhap nam: ");
	scanf("%d", &nam);

	int tongTien = 0;
	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.nam == nam)
		{
			tongTien += p->Info.giaGui;
		}
	}
	printf("Tong tien cua nam %d la: %d\n", nam, tongTien);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4G(SList dsVao)
{
	// in danh sách xe trong bãi
	system("cls");
	inDSXeVao(dsVao);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4H(SList dsVao)
{
	// in danh sách xe trong bãi giảm dần theo giờ gửi
	system("cls");

	printf("DANH SACH XE TRONG BAI GIAM DAN THEO GIO GUI.\n");

	if (isEmpty(dsVao) == 1)
	{
		printf("Danh sach rong!\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
		return;
	}
	for (SNode* p = dsVao.Head; p->Next != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			timeAuto(&p->Info.gioRa.ngay, &p->Info.gioRa.thang, &p->Info.gioRa.nam, &p->Info.gioRa.gio, &p->Info.gioRa.phut);
			timeAuto(&q->Info.gioRa.ngay, &q->Info.gioRa.thang, &q->Info.gioRa.nam, &q->Info.gioRa.gio, &q->Info.gioRa.phut);

			if (tinhGioGuiXe(p->Info.gioVao, p->Info.gioRa) < tinhGioGuiXe(q->Info.gioVao, q->Info.gioRa))
				swap(p->Info, q->Info);
		}
	}
	inDSXeVao(dsVao);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4I(SList dsRa)
{
	// in danh sách xe trong lịch sử
	system("cls");
	inDSXeRa(dsRa);
	printf("NHAN ENTER DE TIEP TUC.\n");

	getch();
}

void chucNang4J(SList dsRa)
{
	system("cls");
	// in danh sách lịch sử theo ngày ra

	int ngay, thang, nam;
	nhapNgayThangNam(ngay, thang, nam);

	int ktra = 0;

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.ngay == ngay)
		{
			show1XeRa(p->Info);
			ktra = 1;
		}
	}

	if (ktra == 0)
		printf("KHONG CO XE NAO TRONG NGAY NAY.\n");

	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4K(SList dsRa)
{
	system("cls");
	// in danh sách lịch sử theo tháng ra

	int thang, nam;

	do
	{
		printf("Nhap thang: ");
		scanf("%d", &thang);

		printf("Nhap nam: ");
		scanf("%d", &nam);

		if (thang > 12 && thang < 1)
			printf("Vui long xem lai!\n");

	} while (thang > 12 && thang < 1);



	int ktra = 0;

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.thang == thang)
		{
			show1XeRa(p->Info);
			ktra = 1;
		}
	}

	if (ktra == 0)
		printf("KHONG CO XE NAO TRONG THANG NAY.\n");

	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4L(SList dsRa)
{
	system("cls");
	// in danh sách lịch sử theo năm ra

	int nam;

	printf("Nhap nam can xem: ");
	scanf("%d", &nam);

	int ktra = 0;

	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if (p->Info.gioRa.nam == nam)
		{
			show1XeRa(p->Info);
			ktra = 1;
		}
	}

	if (ktra == 0)
		printf("KHONG CO XE NAO TRONG NAM NAY.\n");

	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4M(Stack dsVaoGN)
{
	system("cls");
	inDsXeVaoGanNhat(dsVaoGN);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4N(Stack dsRaGN)
{
	system("cls");
	inDsXeRaGanNhat(dsRaGN);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang4O(SList dsRa)
{
	// tính tổng tiền từ ngày đến ngày
	int ngayBatDau, thangBatDau, namBatDau;
	int ngayKetThuc, thangKetThuc, namKetThuc;

	system("cls");
	do
	{
		printf("Nhap ngay bat dau: ");
		scanf("%d", &ngayBatDau);
		printf("Nhap thang bat dau: ");
		scanf("%d", &thangBatDau);
		printf("Nhap nam bat dau: ");
		scanf("%d", &namBatDau);

		printf("Nhap ngay ket thuc: ");
		scanf("%d", &ngayKetThuc);
		printf("Nhap thang ket thuc: ");
		scanf("%d", &thangKetThuc);
		printf("Nhap nam ket thuc: ");
		scanf("%d", &namKetThuc);

		if (ngayBatDau > ngayKetThuc && thangBatDau == thangKetThuc && namBatDau == namKetThuc ||
			thangBatDau > thangKetThuc && namBatDau == namKetThuc || namBatDau > namKetThuc)
			printf("VUI LONG KIEM TRA LAI THONG TIN.\n");

	} while (ngayBatDau > ngayKetThuc && thangBatDau == thangKetThuc && namBatDau == namKetThuc ||
		thangBatDau > thangKetThuc && namBatDau == namKetThuc || namBatDau > namKetThuc);



	int tongTien = 0;
	for (SNode* p = dsRa.Head; p != NULL; p = p->Next)
	{
		if ((p->Info.gioRa.nam > namBatDau || (p->Info.gioRa.nam == namBatDau && p->Info.gioRa.thang > thangBatDau) || (p->Info.gioRa.nam == namBatDau && p->Info.gioRa.thang == thangBatDau && p->Info.gioRa.ngay >= ngayBatDau)) &&
			(p->Info.gioRa.nam < namKetThuc || (p->Info.gioRa.nam == namKetThuc && p->Info.gioRa.thang < thangKetThuc) || (p->Info.gioRa.nam == namKetThuc && p->Info.gioRa.thang == thangKetThuc && p->Info.gioRa.ngay <= ngayKetThuc)))
		{
			tongTien += p->Info.giaGui;
		}
	}
	printf("Tong tien trong khoang tu %d/%d/%d den %d/%d/%d la: %d\n", ngayBatDau, thangBatDau, namBatDau, ngayKetThuc, thangKetThuc, namKetThuc, tongTien);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void ChucNang5(SList dsVao) {
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("                  --- DANH SACH XE GUI QUA 24 GIO ---                 \n");
	int hour, minute, day, month, year;
	timeAuto(&hour, &minute, &day, &month, &year);
	date d = { day, month, year, hour, minute };
	printf("%-10s%-15s%-15s%-18s%-20s\n", "MA XE", "BIEN SO XE", "LOAI XE", "TEN CHU XE", "THOI GIAN VAO");
	if (isEmpty(dsVao) == 1)
		printf("KHONG CO XE GUI QUA 24 GIO!\n");
	else
	{
		for (SNode* p = dsVao.Head; p != NULL; p = p->Next)
		{
			int soGio = tinhGioGuiXe(p->Info.gioVao, d);
			if (soGio > 24){
				show1XeVao(p->Info);
			}
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void MENUChucNang6()
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("*            ---- QUAN LI NHAN VIEN ----             *\n");

	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. HIEN THI DANH SACH NHAN VIEN                   *\n", i); i++;
	printf("* 0%d. THEM NHAN VIEN                                 *\n", i); i++;
	printf("* 0%d. XOA NHAN VIEN                                  *\n", i); i++;
	printf("* 0%d. XEM NHAN VIEN THEO MA                          *\n", i); i++;
	printf("* 0%d. CAP NHAT THONG TIN NHAN VIEN THEO MA           *\n", i); i++;

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void chucNang6A(SListNV dsnv)
{
	system("cls");
	showDSNV(dsnv);
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

int chucNang6B(nhanVien &nv, SListNV& dsnv)
{
	system("cls");

	int ktra = 0;
	do
	{
		nhapTTNV(nv);
		SNodeNV* q = findSNode_TheoMSNV(dsnv, nv);
		if (q != NULL)
		{
			ktra = 1;
		}
		if (ktra == 1)
			printf("TRUNG MA NHAN VIEN\n");

	} while (ktra == 1);

	SNodeNV* p = createSNodeNV(nv);

	if (!p)
	{
		printf("THEM KHONG THANH CONG.\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
		return 0;
	}

	else
	{
		insertTailNV(dsnv, p);
		saveTTNV(dsnv, "dsNhanVien.txt");
		printf("THEM THANH CONG.\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
		return 1;
	}

	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
	return 0;
}

void chucNang6C(nhanVien &nv, SListNV& dsnv)
{
	system("cls");
	int kq = deleteNhanVienTheoMa(dsnv, nv);
	if (kq == 1)
	{
		printf("NHAN VIEN DA BI XOA LA:\n");
		xuatTTNV(nv);
		saveTTNV(dsnv, "dsNhanVien.txt");
	}
	else
	{
		printf("KHONG TIM THAY NHAN VIEN CAN XOA.\n");
	}
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void chucNang6D(nhanVien nv, SListNV dsnv)
{
	system("cls");

	printf("Nhap ma nhan vien can tim: ");
	rewind(stdin);
	gets_s(nv.maNV);

	SNodeNV* p = findSNode_TheoMSNV(dsnv, nv);
	if (p != NULL)
	{
		printf("NHAN VIEN CAN TIM LA:\n");
		xuatTTNV(p->Info);
	}
	else
	{
		printf("KHONG TIM THAY NHAN VIEN.\n");
	}
	printf("NHAN ENTER DE TIEP TUC.\n");
	getch();
}

void MENUChucNang6E()
{
	system("cls");
	int i = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*        ---- CAP NHAP THONG TIN NHAN VIEN ----      *\n");
	printf("* 0%d. THOAT                                          *\n", i); i++;
	printf("* 0%d. SUA MA NHAN VIEN                               *\n", i); i++;
	printf("* 0%d. SUA HO TEN NHAN VIEN                           *\n", i); i++;
	printf("* 0%d. SUA CHUC VU NHAN VIEN                          *\n", i); i++;
	printf("* 0%d. SUA MAT KHAU NHAN VIEN                         *\n", i); i++;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int chucNang6E(nhanVien &nv, SListNV& dsnv)
{
	system("cls");

	char FILENAME[] = "dsNhanVien.txt";
	printf("NHAP MA NHAN VIEN CAN CAP NHAT: ");
	rewind(stdin);
	gets(nv.maNV);

	SNodeNV* p = findSNode_TheoMSNV(dsnv, nv);

	if (!p)
	{
		printf("KHONG TIM THAY NHAN VIEN CAN SUA.\n");
		printf("NHAN ENTER DE TIEP TUC.\n");
		getch();
		return 0;
	}

	else
	{
		int chon;
		do
		{
			MENUChucNang6E();
			printf("CHON CHUC NANG CHUONG TRINH: ");
			scanf("%d", &chon);

			switch (chon)
			{
			case 0:
			{
					  printf("THOAT.\n");
					  break;
			}

			case 1:
			{
					  printf("DANG CHINH SUA NHAN VIEN:\n");
					  xuatTTNV(p->Info);
					  printf("NHAP MA NHAN VIEN CAN CAP NHAT: ");
					  rewind(stdin);
					  gets_s(p->Info.maNV);
					  saveTTNV(dsnv, FILENAME);
					  printf("CAP NHAT THANH CONG.\n");
					  xuatTTNV(p->Info);
					  printf("NHAN ENTER DE TIEP TUC.\n");
					  getch();
					  break;
			}

			case 2:
			{
					  printf("DANG CHINH SUA NHAN VIEN:\n");
					  xuatTTNV(p->Info);
					  printf("NHAP TEN NHAN VIEN CAN CAP NHAT: ");
					  rewind(stdin);
					  gets_s(p->Info.tenNV);
					  saveTTNV(dsnv, FILENAME);
					  printf("CAP NHAT THANH CONG.\n");
					  xuatTTNV(p->Info);
					  printf("NHAN ENTER DE TIEP TUC.\n");
					  getch();
					  break;
			}

			case 3:
			{
					  printf("DANG CHINH SUA NHAN VIEN:\n");
					  xuatTTNV(p->Info);
					  printf("NHAP CHUC VU NHAN VIEN CAN CAP NHAT: ");
					  rewind(stdin);
					  gets_s(p->Info.chucVu);
					  saveTTNV(dsnv, FILENAME);
					  printf("CAP NHAT THANH CONG.\n");
					  xuatTTNV(p->Info);
					  printf("NHAN ENTER DE TIEP TUC.\n");
					  getch();
					  break;
			}

			case 4:
			{
					  printf("DANG CHINH SUA NHAN VIEN:\n");
					  xuatTTNV(p->Info);
					  printf("NHAP MAT KHAU CAN CAP NHAT: ");
					  rewind(stdin);
					  gets_s(p->Info.matKhau);
					  saveTTNV(dsnv, FILENAME);
					  printf("CAP NHAT THANH CONG.\n");
					  xuatTTNV(p->Info);
					  printf("NHAN ENTER DE TIEP TUC.\n");
					  getch();
					  break;
			}
			default:
				printf("KHONG CO CHUC NANG NAY.\n");
				break;
			}
		} while (chon != 0);
	}
}