# Models
Models xử lý dữ liệu, đồng bộ giữa SQL Server và danh sách liên kết.
## 1. Bảng Bill
### 1.1 Thêm
#### 1.1.1 Định nghĩa hàm
`int insert(List<Menu>&, const Menu&);`
#### 1.1.2 Chức năng
Hàm thêm tham chiếu *const Menu&* vào tham chiếu *List<Menu>&* và sau đó thực hiện việc insert dữ liệu của tham chiếu *const Menu&* lên SQL Server.
Sau đó select MENU từ SQL server để đồng bộ dữ liệu với danh sách liên kết.
### 1.2 Sửa
#### 1.2.1 Định nghĩa hàm
`int update(List<Menu>&, const Menu&);`
#### 1.2.2 Chức năng
Hàm cập nhật tham chiếu *const Menu&* vào tham chiếu *List<Menu>&* và sau đó thực hiện việc update dữ liệu của tham chiếu *const Menu&* lên SQL Server.
Sau đó select MENU từ SQL server để đồng bộ dữ liệu với danh sách liên kết.
  
  
	int remove(List<Menu>&, const Menu&);
	int select(List<Menu>&);

	int insert(List<Desk>&, const Desk&);
	int remove(List<Desk>&, const Desk&);
	int select(List<Desk>&);

	int insert(List<Bill>&, const Bill&);
	int update(List<Bill>&, const Bill&);
	int select(List<Bill>&);

	int insert(List<AddFood>&, const AddFood&);
	int select(List<AddFood>&);
