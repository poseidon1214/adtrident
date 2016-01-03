-- MySQL dump 10.13  Distrib 5.5.30, for Linux (x86_64)
--
-- Host: localhost    Database: adtrident_db
-- ------------------------------------------------------
-- Server version	5.5.30-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `black_list`
--

DROP TABLE IF EXISTS `black_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `black_list` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_type` varchar(100) NOT NULL,
  `id_value` varchar(500) NOT NULL,
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `black_list`
--

LOCK TABLES `black_list` WRITE;
/*!40000 ALTER TABLE `black_list` DISABLE KEYS */;
INSERT INTO `black_list` VALUES (1,'ip','116.247.112.152','2015-12-03 20:11:44','2015-12-03 20:11:44'),(2,'ip','116.247.112.151','2015-12-03 20:11:50','2015-12-03 20:11:50');
/*!40000 ALTER TABLE `black_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `idea`
--

DROP TABLE IF EXISTS `idea`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `idea` (
  `level` int(11) DEFAULT '4',
  `ideaid` int(11) NOT NULL,
  `unitid` int(11) NOT NULL,
  `planid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `title` varchar(1000) DEFAULT NULL,
  `desc1` varchar(1000) DEFAULT NULL,
  `url` varchar(1000) DEFAULT NULL,
  `showurl` varchar(1000) DEFAULT NULL,
  `creative_type` int(11) NOT NULL DEFAULT '1',
  `height` int(11) NOT NULL DEFAULT '0',
  `width` int(11) NOT NULL DEFAULT '0',
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`ideaid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `idea`
--

LOCK TABLES `idea` WRITE;
/*!40000 ALTER TABLE `idea` DISABLE KEYS */;
INSERT INTO `idea` VALUES (4,5,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,600,120,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,6,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,600,160,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,7,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,200,200,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,8,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,250,250,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,9,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,250,300,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,10,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,280,336,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,11,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,60,468,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,12,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,60,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,13,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,80,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,14,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,90,728,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,15,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,60,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,16,3,3,2,'','','http://nankem.cdjlgk.com/zt/2015-10/20151031/','',1,90,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,17,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,600,120,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,18,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,600,160,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,19,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,200,200,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,20,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,250,250,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,21,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,250,300,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,22,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,280,336,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,23,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,60,468,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,24,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,60,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,25,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,80,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,26,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,90,728,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,27,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,60,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,28,4,3,2,'','','http://nankem.cdjlgk.com/zt/2015-11/20141218/','',1,90,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,29,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,600,120,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,30,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,600,160,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,31,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,200,200,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,32,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,250,250,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,33,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,250,300,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,34,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,280,336,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,35,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,60,468,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,36,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,60,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,37,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,80,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,38,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,90,728,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,39,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,60,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,40,5,4,2,'','','http://nanke.cdjlgk.com/zt/2015-10/20151030/','',1,90,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,41,6,4,2,'','','http://nanke.cdjlgk.com/','',1,600,120,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,42,6,4,2,'','','http://nanke.cdjlgk.com/','',1,600,160,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,43,6,4,2,'','','http://nanke.cdjlgk.com/','',1,200,200,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,44,6,4,2,'','','http://nanke.cdjlgk.com/','',1,250,250,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,45,6,4,2,'','','http://nanke.cdjlgk.com/','',1,250,300,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,46,6,4,2,'','','http://nanke.cdjlgk.com/','',1,280,336,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,47,6,4,2,'','','http://nanke.cdjlgk.com/','',1,60,468,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,48,6,4,2,'','','http://nanke.cdjlgk.com/','',1,60,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,49,6,4,2,'','','http://nanke.cdjlgk.com/','',1,80,640,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,50,6,4,2,'','','http://nanke.cdjlgk.com/','',1,90,728,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,51,6,4,2,'','','http://nanke.cdjlgk.com/','',1,60,960,'2015-12-13 15:22:11','2015-12-13 15:22:11'),(4,52,6,4,2,'','','http://nanke.cdjlgk.com/','',1,90,960,'2015-12-13 15:22:11','2015-12-13 15:22:11');
/*!40000 ALTER TABLE `idea` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plan`
--

DROP TABLE IF EXISTS `plan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `plan` (
  `level` int(11) DEFAULT '2',
  `planid` int(11) NOT NULL,
  `userid` int(11) DEFAULT NULL,
  `planstatid` int(11) NOT NULL DEFAULT '0',
  `ipblack` varchar(1000) DEFAULT '0',
  `negative` varchar(1000) DEFAULT '0',
  `cyc` varchar(1000) DEFAULT '0',
  `region` varchar(1000) DEFAULT NULL,
  `budget` bigint(20) DEFAULT '0',
  `consume` bigint(20) DEFAULT '0',
  `gender` int(11) DEFAULT '0',
  `taste` varchar(1000) DEFAULT '0',
  `sitecate` varchar(1000) DEFAULT '0',
  `exactnegative` varchar(1000) DEFAULT '0',
  `flowtype` varchar(100) DEFAULT NULL,
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`planid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plan`
--

LOCK TABLES `plan` WRITE;
/*!40000 ALTER TABLE `plan` DISABLE KEYS */;
INSERT INTO `plan` VALUES (2,3,2,0,'0:DFT','0:DFT','10-18;10-22;10-18;10-18;10-18;10-18;10-18','1:³É¶¼',10000,0,2,'0:DFT','0:DFT','0:DFT','mobile','2015-12-13 15:22:11','2015-12-13 15:22:11'),(2,4,2,0,'0:DFT','0:DFT','10-18;10-22;10-18;10-18;10-18;10-18;10-18','1:³É¶¼',10000,0,2,'0:DFT','0:DFT','0:DFT','pc','2015-12-13 15:22:11','2015-12-13 15:22:11');
/*!40000 ALTER TABLE `plan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `site`
--

DROP TABLE IF EXISTS `site`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `site` (
  `siteid` int(11) NOT NULL,
  `url` varchar(2048) DEFAULT NULL,
  `title` varchar(1000) DEFAULT NULL,
  `description` varchar(1000) DEFAULT NULL,
  `keywords` varchar(1000) DEFAULT '0',
  `cate` varchar(1000) DEFAULT NULL,
  `disease` varchar(1000) DEFAULT NULL,
  `symptom` varchar(1000) DEFAULT NULL,
  `department` varchar(1000) DEFAULT NULL,
  `complication` varchar(1000) DEFAULT NULL,
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`siteid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `site`
--

LOCK TABLES `site` WRITE;
/*!40000 ALTER TABLE `site` DISABLE KEYS */;
/*!40000 ALTER TABLE `site` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `test`
--

DROP TABLE IF EXISTS `test`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `test` (
  `id` int(11) NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `test`
--

LOCK TABLES `test` WRITE;
/*!40000 ALTER TABLE `test` DISABLE KEYS */;
INSERT INTO `test` VALUES (1,'xixihaha'),(2,'xixfsdgsfgihaha'),(3,'fsgfgihaha');
/*!40000 ALTER TABLE `test` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unit`
--

DROP TABLE IF EXISTS `unit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `unit` (
  `level` int(11) DEFAULT '3',
  `unitid` int(11) NOT NULL,
  `planid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `unitbid` int(11) NOT NULL,
  `negative` varchar(1000) DEFAULT '0',
  `exactnegative` varchar(1000) DEFAULT '0',
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`unitid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `unit`
--

LOCK TABLES `unit` WRITE;
/*!40000 ALTER TABLE `unit` DISABLE KEYS */;
INSERT INTO `unit` VALUES (3,3,3,2,100,'0:DFT','0:DFT','2015-12-13 15:22:11','2015-12-13 15:22:11'),(3,4,3,2,100,'0:DFT','0:DFT','2015-12-13 15:22:11','2015-12-13 15:22:11'),(3,5,4,2,100,'0:DFT','0:DFT','2015-12-13 15:22:11','2015-12-13 15:22:11'),(3,6,4,2,100,'0:DFT','0:DFT','2015-12-13 15:22:11','2015-12-13 15:22:11');
/*!40000 ALTER TABLE `unit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `level` int(11) DEFAULT '1',
  `userid` int(11) NOT NULL,
  `ustatid` int(11) NOT NULL DEFAULT '0',
  `ipblack` varchar(1000) DEFAULT '0',
  `region` varchar(1000) DEFAULT '0',
  `budget` bigint(20) DEFAULT '0',
  `budget_all` bigint(20) DEFAULT '0',
  `consume` bigint(20) DEFAULT '0',
  `consume_all` bigint(20) DEFAULT '0',
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,2,0,'0:DFT','1:³É¶¼',10000,1000000,0,0,'2015-12-13 15:22:11','2015-12-13 15:22:11');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `win_notice`
--

DROP TABLE IF EXISTS `win_notice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `win_notice` (
  `reqid` varchar(100) NOT NULL,
  `price` varchar(100) NOT NULL,
  `creative_id` varchar(100) NOT NULL,
  `style_type` varchar(100) NOT NULL,
  `index` varchar(1000) DEFAULT NULL,
  `ext_data` varchar(1000) DEFAULT NULL,
  `cdate` datetime NOT NULL,
  `udate` datetime NOT NULL,
  PRIMARY KEY (`reqid`)
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `win_notice`
--

LOCK TABLES `win_notice` WRITE;
/*!40000 ALTER TABLE `win_notice` DISABLE KEYS */;
/*!40000 ALTER TABLE `win_notice` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-12-17 18:21:37
