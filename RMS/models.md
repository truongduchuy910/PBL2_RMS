# Models
Models xử lý dữ liệu, đồng bộ giữa SQL Server và danh sách liên kết.
## Khai báo
    Models tên_biến;
## 1. BẢNG DESKS

### 1.1 Thêm
#### 1.1.1 Định nghĩa hàm
    int insert(List<Menu>&, const Menu&);
#### 1.1.2 Chức năng
- Thêm biến vào danh sách liên kết.
- Đồng bộ biến lên SQL Server.

### 1.2 Sửa
#### 1.2.1 Định nghĩa hàm
    int update(List<Menu>&, const Menu&);
#### 1.2.2 Chức năng
- Cập nhật biến vào danh sách liên kết.
- Cập nhật dữ liệu biến lên SQL Server.

### 1.3 Xóa
#### 1.3.1 Định nghĩa hàm
	int remove(List<Menu>&, const Menu&);
#### 1.3.2 Chức năng
- Xóa biến ở danh sách liên kết.
- Xóa dữ liệu biến lên SQL Server.

### 1.4 Cập Nhật
#### 1.3.1 Định nghĩa hàm
	int select(List<Menu>&);
#### 1.3.2 Chức năng
- Cập nhật lại danh sách liên kết từ SQL Server.

## 2. BẢNG DESK

### 2.1 Thêm
#### 2.1.1 Định nghĩa hàm
	int insert(List<Desk>&, const Desk&);
#### 2.1.2 Chức năng
- Thêm biến vào danh sách liên kết.
- Đồng bộ biến lên SQL Server.
- Cập nhật lại danh sách liên kết từ SQL Server.

### 2.2 Xóa
#### 2.3.1 Định nghĩa hàm
	int remove(List<Desk>&, const Desk&);
#### 2.3.2 Chức năng
- Xóa biến ở danh sách liên kết.
- Xóa dữ liệu biến lên SQL Server.
- Cập nhật lại danh sách liên kết từ SQL Server.

### 2.3 Cập Nhật
#### 2.3.1 Định nghĩa hàm
	int select(List<Menu>&);
#### 2.3.2 Chức năng
- Cập nhật lại danh sách liên kết từ SQL Server.

	int select(List<Desk>&);

	int insert(List<Bill>&, const Bill&);
	int update(List<Bill>&, const Bill&);
	int select(List<Bill>&);

	int insert(List<AddFood>&, const AddFood&);
	int select(List<AddFood>&);
