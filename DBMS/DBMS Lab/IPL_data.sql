-- MySQL dump 10.13  Distrib 8.0.45, for Linux (x86_64)
--
-- Host: localhost    Database: university
-- ------------------------------------------------------
-- Server version	8.0.45-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `IPL`
--

DROP TABLE IF EXISTS `IPL`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `IPL` (
  `YEAR` int NOT NULL,
  `VENUE` char(50) DEFAULT NULL,
  `WINNER` char(30) DEFAULT NULL,
  `PoS` char(30) DEFAULT NULL,
  `ORGANIZER` char(30) DEFAULT NULL,
  PRIMARY KEY (`YEAR`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `IPL`
--

LOCK TABLES `IPL` WRITE;
/*!40000 ALTER TABLE `IPL` DISABLE KEYS */;
INSERT INTO `IPL` VALUES (2008,'India','Rajasthan Royals','Shane Watson','India'),(2009,'South Africa','Deccan Chargers','Adam Gilchrist','India'),(2010,'South Africa','Chennai Super Kings','Sachin Tendulkar','India'),(2013,'India','Chennai Super Kings','Chris Gayle','UAE'),(2014,'India, UAE','Kolkata Knight Riders','Gleen Maxwell','India'),(2015,'India','Mumbai Indians','Andre Mark Russell','India'),(2020,'UAE','Mumbai Indians','Jofra Archer','India'),(2021,'India','Mumbai Indians','Chris Gayle','UAE');
/*!40000 ALTER TABLE `IPL` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-03-23 16:53:03
