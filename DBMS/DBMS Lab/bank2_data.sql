
DROP TABLE IF EXISTS `BANK2`;
CREATE TABLE `BANK2` (
  `ID` int NOT NULL,
  `Customer_Name` varchar(100) DEFAULT NULL,
  `Account_Type` varchar(50) DEFAULT NULL,
  `YEAR` int DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

LOCK TABLES `BANK2` WRITE;
INSERT INTO `BANK2` VALUES (11110001,'John Trevor','Current',2018),(11110002,'Anurak Eshin','Savings',2019),(11110003,'Somlata Sen','Current',2019),(11110004,'Ezhil Swami','Current',2019),(11110005,'Panna Singh','Savings',2019),(11110006,'Aarohi Tendulkar','Savings',2020),(11110007,'Aravind Babu','Current',2020),(11110008,'Jahanara Begum','Savings',2020),(11110009,'Aarohi Tendulkar','Current',2021);
UNLOCK TABLES;
