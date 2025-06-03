#include "tranBao.h"

void chucNang1(SList& dsVao, Itemtype& x, Stack& dsVaoGN, NV user)
{
	// Được viết bởi Nguyễn Ngọc Châu
	int chucNang01;

	do
	{
		MENUChucNang1(user);
		printf("CHON CHUC NANG CHUONG TRINH: ");
		scanf("%d", &chucNang01);

		switch (chucNang01)
		{
		case 0:
		{
				  printf("Thoat.\n");
				  break;
		}

		case 1:
		{
				  chucNang1A(dsVao, x, dsVaoGN);
				  break;
		}

		default:
			printf("KHONG CO CHUC NANG NAY!\n");
			printf("NHAN ENTER DE TIEP TUC.\n");
			getch();
			break;
		}
	} while (chucNang01 != 0);


}

void chucNang2(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN, NV user)
{
	// Được viết bởi Nguyễn Ngọc Châu
	int chucNang02;

	do
	{
		MENUChucNang2(user);
		printf("CHON CHUC NANG CHUONG TRINH: ");
		scanf("%d", &chucNang02);

		switch (chucNang02)
		{
		case 0:
		{
				  printf("Thoat.\n");
				  break;
		}

		case 1:
		{
				  chucNang2A(dsVao, dsRa, x, dsRaGN);
				  break;
		}

		case 2:
		{
				  chucNang2B(dsVao, dsRa, x, dsRaGN);
				  break;
		}

		default:
			printf("KHONG CO CHUC NANG NAY!\n");
			printf("NHAN ENTER DE TIEP TUC.\n");
			getch();
			break;
		}
	} while (chucNang02 != 0);
}

void chucNang3(SList dsVao, SList dsRa, NV user)
{
	// Được viết bởi Nguyễn Thế Anh
	int chucNang03;

	do
	{
		MENUChucNang3(user);
		printf("CHON CHUC NANG CHUONG TRINH: ");
		scanf("%d", &chucNang03);
		switch (chucNang03)
		{

		case 0:
		{
				  printf("Thoat.\n");
				  break;
		}

		case 1:
		{
				  chucNang3A(dsVao, dsRa);
				  break;
		}

		case 2:
		{
				  chucNang3B(dsVao, dsRa);
				  break;
		}

		case 3:
		{
				  chucNang3C(dsVao, dsRa);
				  break;
		}

		case 4:
		{
				  chucNang3D(dsVao, dsRa);
				  break;
		}

		default:
			printf("KHONG CO CHUC NANG NAY!\n");
			printf("NHAN ENTER DE TIEP TUC.\n");
			getch();
			break;
		}
	} while (chucNang03 != 0);
}

void chucNang4(SList dsVao, SList dsRa, Stack dsVaoGN, Stack dsRaGN, NV user)
{
	// Được viết bởi Lý Vĩnh Đức
	int chucNang04;

	do
	{
		MENUChucNang4(user);
		printf("CHON CHUC NANG CHUONG TRINH: ");
		scanf("%d", &chucNang04);
		switch (chucNang04)
		{

		case 0:
		{
				  printf("Thoat.\n");
				  break;
		}

		case 1:
		{
				  chucNang4A(dsVao);
				  break;
		}

		case 2:
		{
				  chucNang4AA(dsVao);
				  break;
		}

		case 3:
		{
				  chucNang4B(dsVao);
				  break;
		}

		case 4:
		{
				  chucNang4C(dsVao);
				  break;
		}

		case 5:
		{
				  chucNang4D(dsRa);
				  break;
		}

		case 6:
		{
				  chucNang4E(dsRa);
				  break;
		}

		case 7:
		{
				  chucNang4F(dsRa);
				  break;
		}

		case 8:
		{
				  chucNang4O(dsRa);
				  break;
		}

		case 9:
		{
				  chucNang4G(dsVao);
				   break;
		}

		case 10:
		{
				  chucNang4H(dsVao);
				  break;
		}

		case 11:
		{
				  chucNang4I(dsRa);
				  break;
		}

		case 12:
		{
				  chucNang4J(dsRa);
				  break;
		}

		case 13:
		{
				  chucNang4K(dsRa);
				  break;
		}

		case 14:
		{
				   chucNang4L(dsRa);
				   break;
		}
		
		case 15:
		{
				   chucNang4M(dsVaoGN);
				   break;
		}

		case 16:
		{
				   chucNang4N(dsRaGN);
				   break;
		}
		
		default:
			printf("KHONG CO CHUC NANG NAY!\n");
			printf("NHAN ENTER DE TIEP TUC.\n");
			getch();
			break;
		}
	} while (chucNang04 != 0);
}

void chucNang5(SList dsVao) {
	// Được viết bởi Trần Dương Gia Bảo
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                  --- DANH SACH XE GUI QUA 24 GIO ---                 *\n");
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

void chucNang6(SListNV& dsnv, NV& nv)
{
	// Được viết bởi Trần Gia Bảo
	int chucNang06;

	do
	{
		MENUChucNang6();
		printf("CHON CHUC NANG CHUONG TRINH: ");
		scanf("%d", &chucNang06);
		switch (chucNang06)
		{

		case 0:
		{
				  printf("Thoat.\n");
				  break;
		}

		case 1:
		{
				  chucNang6A(dsnv);
				  break;
		}

		case 2:
		{
				  chucNang6B(nv, dsnv);
				  break;
		}

		case 3:
		{
				  chucNang6C(nv, dsnv);
				  break;
		}

		case 4:
		{
				  chucNang6D(nv, dsnv);
				  break;
		}

		case 5:
		{
				  chucNang6E(nv, dsnv);
				  break;
		}

		default:
			printf("KHONG CO CHUC NANG NAY!\n");
			printf("NHAN ENTER DE TIEP TUC.\n");
			getch();
			break;
		}
	} while (chucNang06 != 0);
}

void main()
{
	// Được viết bởi Trần Gia Bảo
	int chucNangChuongTrinh;
	do
	{

		Itemtype x;

		SList dsVao;
		initSList(dsVao);

		SList dsRa;
		initSList(dsRa);

		loadfileXeVao(dsVao, "xeVaoBai.txt");
		loadfileLichSuXeTrongBai(dsRa, "lichSuXeTrongBai.txt");

		Stack dsVaoGN;
		initStack(dsVaoGN);

		Stack dsRaGN;
		initStack(dsRaGN);

		SListNV dsnv;
		NV nv;
		initSListNV(dsnv);
		createSListDSNV_FromTextFile(dsnv, "dsNhanVien.txt");


		loiChao();
		Sleep(500);
		system("cls");

		banQuyen();

		NV user;
		dangNhap(user, dsnv);
		int ktraQuanLi = kiemTraQuanLi(user);

		do
		{
			MENUChuongTrinh(user);
			printf("CHON CHUC NANG CHUONG TRINH: ");
			scanf("%d", &chucNangChuongTrinh);

			switch (chucNangChuongTrinh)
			{
			case 0:
			{
					  system("cls");
					  veHinhTraiTim();
					  system("cls");
					  break;
			}

			case 1:
			{
					  chucNang1(dsVao, x, dsVaoGN, user);
					  break;
			}

			case 2:
			{
					  chucNang2(dsVao, dsRa, x, dsRaGN, user);
					  break;

			}

			case 3:
			{

					  chucNang3(dsVao, dsRa, user);
					  break;
			}

			case 4:
			{

					  chucNang4(dsVao, dsRa, dsVaoGN, dsRaGN, user);
					  break;
			}

			case 5:
			{
					  chucNang5(dsVao);
					  break;
			}

			case 6:
			{
					  if (ktraQuanLi == 1)
						  chucNang6(dsnv, nv);
					  else
					  {
						  printf("KHONG CO CHUC NANG NAY!\n");
						  printf("NHAN ENTER DE TIEP TUC.\n");
						  getch();
					  }
					  break;
			}
			default:
				printf("KHONG CO CHUC NANG NAY!\n");
				printf("NHAN ENTER DE TIEP TUC.\n");
				getch();
				break;
			}

		} while (chucNangChuongTrinh != 0);

		system("cls");
	} while (chucNangChuongTrinh == 0);
	getch();
}