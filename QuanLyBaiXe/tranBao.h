#ifndef tranGiaBao_h
#define tranGiaBao_h

#pragma once

#include "DuongBao.h"

#define MaxCho 300

// Nhập và lưu
void nhapNgayThangNam(int& ngay, int& thang, int& nam);

void nhapThoiGianVao(Itemtype& x);

void nhapThoiGianRa(Itemtype& x);

void nhap1Xe(Itemtype& x);

int saveVaoDsXeVaoBai(SList dsVao, char FILENAME[]);

int saveVaoDsXeRaBai(SList dsRa, char FILENAME[]);

int loadfileXeVao(SList& dsVao, char FILENAME[]);

int loadfileLichSuXeTrongBai(SList& dsRa, char FILENAME[]);

int themVaoDsLuotXeVaoGanNhat(Stack& st, Itemtype x);

int themVaoDsLuotXeRaGanNhat(Stack& st, Itemtype x);

int demSoChoConLai(SList dsVao);

// in danh sach

void show1XeVao(Itemtype x);

void show1XeRa(Itemtype x);

void inDSXeVao(SList dsVao);

void inDSXeRa(SList dsRa);

void inDsXeVaoGanNhat(Stack st);

void inDsXeRaGanNhat(Stack st);

// Tim kiem

SNode* findsTheoBienSoXe(SList dsVao, Itemtype x);

SNode* findsTheoMaXe(SList dsVao, Itemtype x);

SNode* findsTheoTenChuXe(SList dsVao, Itemtype x);

void timKiemTheoBienSoXe(SList dsVao, SList dsRa);

void timKiemTheoMaXe(SList dsVao, SList dsRa);

void timKiemTheoTenChuXe(SList dsVao, SList dsRa);

void timKiemTheoLoaiXe(SList dsVao, SList dsRa);

// Thêm xe vào bãi

int themXeVaoBai(SList& dsVao, Itemtype& x, Stack& dsVaoGN);

// tính tiền

int tinhGioGuiXe(date vao, date ra);

int kiemTraGioQuyDinh(date vao, date ra);

void timNgayHomSau(int& ngay, int& thang, int& nam);

int kiemTraPhat(Itemtype x);

void nhapVeXemPhim(Itemtype &x);

int tinhTienXeOto(Itemtype x);

int tinhTienXeMay(Itemtype x);

int tinhTienXeDap(Itemtype x);

int tinhTienGuiXe(Itemtype x);

int tinhTienTuNgayDenNgay(SList dsRa, int ngayBatDau, int thangBatDau, int namBatDau, int ngayKetThuc, int thangKetThuc, int namKetThuc);

// Xoa xe khoi bai

int xeRoiBai_TheoBienSo(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN);

int xeRoiBai_TheoMaXe(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN);

// Nhan Vien

int kiemTraQuanLi(nhanVien nv);

int kiemTraDangNhap(nhanVien nv, SListNV dsnv);

// Loi chao

void banQuyen();

void veHinhTraiTim();

void load();

void loiChao();

int dangNhap(NV& nv, SListNV dsnv);

// Các chức năng

void MENUChuongTrinh(NV user);

void MENUChucNang1(NV user);

void chucNang1A(SList& dsVao, Itemtype& x, Stack& st);

void MENUChucNang2(NV user);

void chucNang2A(SList& dsVao, SList& dsRa, Itemtype& x, Stack& dsRaGN);

void chucNang2B(SList& dsVao, SList& dsRa, Itemtype& x, Stack& st);

void MENUChucNang3(NV user);

void chucNang3A(SList dsVao, SList dsRa);

void chucNang3B(SList dsVao, SList dsRa);

void chucNang3C(SList dsVao, SList dsRa);

void chucNang3D(SList dsVao, SList dsRa);

void MENUChucNang4(NV user);

void chucNang4A(SList dsVao);

void chucNang4AA(SList dsVao);

void chucNang4B(SList dsVao);

void chucNang4C(SList dsVao);

void chucNang4D(SList dsRa);

void chucNang4E(SList dsRa);

void chucNang4F(SList dsRa);

void chucNang4G(SList dsVao);

void chucNang4H(SList dsVao);

void chucNang4I(SList dsRa);

void chucNang4J(SList dsRa);

void chucNang4K(SList dsRa);

void chucNang4L(SList dsRa);

void chucNang4M(Stack dsVaoGN);

void chucNang4N(Stack dsRaGN);

void chucNang4O(SList dsRa);

void ChucNang5(SList dsVao);

void MENUChucNang6();

void chucNang6A(SListNV dsnv);

int chucNang6B(nhanVien &nv, SListNV& dsnv);

void chucNang6C(nhanVien &nv, SListNV& dsnv);

void chucNang6D(nhanVien nv, SListNV dsnv);

void MENUChucNang6E();

int chucNang6E(nhanVien &nv, SListNV& dsnv);

#endif