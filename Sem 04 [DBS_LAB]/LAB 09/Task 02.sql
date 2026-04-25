-- Customers
INSERT INTO Customer VALUES (1, 'Ali Raza',    '0321-1111111', 'ali@email.com',   'Karachi');
INSERT INTO Customer VALUES (2, 'Hina Malik',  '0321-2222222', 'hina@email.com',  'Lahore');
INSERT INTO Customer VALUES (3, 'Bilal Ahmed', '0321-3333333', 'bilal@email.com', 'Islamabad');

-- Restaurants
INSERT INTO Restaurant VALUES (1, 'Burger Barn',  'Fast Food',  'Karachi',    '021-1234567');
INSERT INTO Restaurant VALUES (2, 'Pizza Palace', 'Italian',    'Lahore',     '042-2345678');
INSERT INTO Restaurant VALUES (3, 'Desi Dhaba',   'Pakistani',  'Islamabad',  '051-3456789');

-- Orders (insert before Delivery since Delivery FK references Order)
INSERT INTO "Order" VALUES (101, DATE '2026-04-20', 1500, 'Delivered', 1, 1);
INSERT INTO "Order" VALUES (102, DATE '2026-04-22', 2200, 'Delivered', 2, 2);
INSERT INTO "Order" VALUES (103, DATE '2026-04-24', 800,  'Confirmed', 3, 3);
INSERT INTO "Order" VALUES (104, DATE '2026-04-25', 1200, 'Pending',   1, 2);
INSERT INTO "Order" VALUES (105, DATE '2026-04-25', 950,  'Pending',   2, 1);

-- Deliveries
INSERT INTO Delivery VALUES (201, 'Kamran Shah',   '0333-1111111', 'Delivered',  101);
INSERT INTO Delivery VALUES (202, 'Tariq Mehmood', '0333-2222222', 'Delivered',  102);
INSERT INTO Delivery VALUES (203, 'Asif Nawaz',    '0333-3333333', 'In Transit', 103);
INSERT INTO Delivery VALUES (204, 'Kamran Shah',   '0333-1111111', 'Pending',    104);
INSERT INTO Delivery VALUES (205, 'Rizwan Ali',    '0333-4444444', 'Pending',    105);

COMMIT;

----Query 1
SELECT o.Order_ID, c.Customer_Name, r.Restaurant_Name, o.Total_Amount, o.Order_Status FROM "Order"     o
JOIN Customer c ON o.Customer_Customer_ID     = c.Customer_ID
JOIN Restaurant r ON o.Restaurant_Restaurant_ID = r.Restaurant_ID
ORDER BY o.Order_Date;

----Query 2
SELECT o.Order_ID, c.Customer_Name, d.Delivery_Person_Name, d.Delivery_Status FROM Delivery d
JOIN "Order" o ON d.Order_Order_ID = o.Order_ID
JOIN Customer c ON o.Customer_Customer_ID = c.Customer_ID
WHERE d.Delivery_Status = 'Pending'
ORDER BY o.Order_ID;
