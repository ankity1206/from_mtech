
DROP TABLE IF EXISTS `BANK1`;
CREATE TABLE `BANK1` (
  `ID` int NOT NULL,
  `Customer_Name` varchar(100) DEFAULT NULL,
  `Account_Type` varchar(50) DEFAULT NULL,
  `YEAR` int DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


LOCK TABLES `BANK1` WRITE;
INSERT INTO `BANK1` VALUES (12340001,'Sai Pallav','Savings',2018),(12340002,'Aarav Roy','Savings',2018),(12340003,'Vihaan Sen','Current',2018),(12340004,'Reyanshi Razdan','Current',2018),(12340005,'Balbindar Singh','Savings',2019),(12340006,'Aarohi Tendulkar','Current',2019),(12340007,'Karthikeyan Murugan','Current',2019),(12340008,'David Barik','Current',2019),(12340009,'Jagannath Mishra','Current',2019),(12340010,'Jahanara Begum','Savings',2020);
UNLOCK TABLES;
