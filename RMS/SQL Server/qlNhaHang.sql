create database qlNhaHang
use qlNhaHang
create table DESK
(
   DeskID int primary key,
   Available bit default('1')
)
create table BILL
(
   BillID int identity(1000,1) primary key,
   DeskID int,
   Payment bit default('0'),
   --payment kiểu true false để biết trạng thái thanh toán
   Total money default(0)
   -- total
)
create table MENU
(
   FoodID int identity(5000,1) primary key,
   --foodId
   FoodName nvarchar(50) not null unique,
   --name
   Cost money 
)
create table ADDFOOD
(
   FoodID int,
   Quantity int not null,
   BillID int
)
GO
alter table BILL
add
   constraint fk_Bill_Desk
   foreign key (DeskID)
   references Desk(DeskID)
GO
alter table ADDFOOD
add 
   constraint fk_AddFood_Menu
   foreign key (FoodID)
   references Menu(FoodID),
   constraint fk_Goimon_Bill
   foreign key (BillID)
   references Bill(BillID)

--Set up Dữ liệu cho table MENU và DESK
Insert into Menu(FoodName,Cost) values
('Saffron',10000),
('Caviar',34.5000),
('Oysters',60),
('White Truffle',330000),
('Iberico Ham',3500),
('Wagyu Beef',600),
('Kopi Luwak Coffee',700),
('Foie Gras',2500),
('Pho',1.5)

Insert into Desk(DeskID) values (1),(2),(3),(4),(5),(6),(7),(8),(9),(10),(11),(12),(13),(14),(15),(16),(17),(18),(19),(20)

--Trigger
--Trả về giá trị False cho DeskID tương ứng khi thêm mới 1 hóa đơn (có DeskID tương ứng) -->Done
Create trigger trg_Insert_Bill
on BILL
for Insert
As
  Update DESK Set DESK.Available = '0'
  From DESK inner join inserted
  On DESK.DeskID = inserted.DeskID

--Trả về giá trị True cho DeskID tương ứng khi update Payment về True -->Done
create trigger trg_Update_Bill_DESK
On BILL
For update
As
  If update(Payment)
    Begin
	declare @Payment bit
	declare @DeskID int
	select @Payment = Payment,@DeskID = DeskID from inserted
	if @Payment = 1 
	  update DESK set Available = 1 where DESK.DeskID = @DeskID 
    End

--Trigger tình Total -->Done
Create Trigger trg_addfood_bill
On ADDFOOD
For Insert
As
  begin
	declare @FoodID int
	declare @Sl int
	declare @BillID int
	declare @Cost money
	select @FoodID = FoodID, @Sl = Quantity, @BillID = BillID from inserted
	select @Cost = Cost from MENU where FoodID = @FoodID
	update BILL
	set Total =Total + @Sl*@Cost where BillID = @BillID
  end
