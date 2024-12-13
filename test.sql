/*
 Navicat Premium Data Transfer

 Source Server         : zhangbo
 Source Server Type    : MySQL
 Source Server Version : 80040
 Source Host           : localhost:3306
 Source Schema         : test

 Target Server Type    : MySQL
 Target Server Version : 80040
 File Encoding         : 65001

 Date: 13/12/2024 08:58:42
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for questionbank
-- ----------------------------
DROP TABLE IF EXISTS `questionbank`;
CREATE TABLE `questionbank`  (
  `id` int(0) NOT NULL,
  `type` int(0) NULL DEFAULT NULL,
  `scoring_question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `choice_question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `subjective_question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `target` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `people_number` int(0) NULL DEFAULT NULL,
  `average_score` int(0) NULL DEFAULT NULL,
  `choice_enable_1` int(0) NULL DEFAULT NULL,
  `choice_enable_2` int(0) NULL DEFAULT NULL,
  `choice_enable_3` int(0) NULL DEFAULT NULL,
  `choice_enable_4` int(0) NULL DEFAULT NULL,
  `choice_optional_1` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `choice_optional_2` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `choice_optional_3` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `choice_optional_4` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of questionbank
-- ----------------------------
INSERT INTO `questionbank` VALUES (1, 1, '字符可读性', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (2, 2, '', '本软件在输入时反应很慢', NULL, NULL, NULL, NULL, 1, 1, 1, NULL, '同意', '不确定', '不同意', NULL);
INSERT INTO `questionbank` VALUES (3, 3, NULL, NULL, '使用本软件遇到的问题', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (4, 1, '字符图像清晰度', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (5, 1, '字符字体辨识度', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (6, 1, '字符与背景的对比度', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (7, 1, '高亮提示部分的帮助', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (8, 1, '高亮使用的颜色', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (9, 1, '闪烁的使用', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (10, 1, '背景颜色的改变', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (11, 1, '界面布局让任务更简单', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (12, 1, '界面显示的信息量', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (13, 1, '界面信息的排列', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
INSERT INTO `questionbank` VALUES (14, 1, '界面信息排列的一致性', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for questionnaire
-- ----------------------------
DROP TABLE IF EXISTS `questionnaire`;
CREATE TABLE `questionnaire`  (
  `questionnaire_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `answer_number` int(0) NULL DEFAULT NULL,
  `questionnaire_description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `create_time` datetime(0) NULL DEFAULT NULL,
  `question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `answer` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `create_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `average_score` int(0) NULL DEFAULT NULL,
  `question_number` int(0) NULL DEFAULT NULL,
  PRIMARY KEY (`questionnaire_name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of questionnaire
-- ----------------------------
INSERT INTO `questionnaire` VALUES ('问卷一', 3, NULL, NULL, '1,2', '9,2', NULL, NULL, NULL);
INSERT INTO `questionnaire` VALUES ('问卷二', 0, NULL, NULL, '3', '留白', NULL, NULL, NULL);

-- ----------------------------
-- Table structure for task
-- ----------------------------
DROP TABLE IF EXISTS `task`;
CREATE TABLE `task`  (
  `task_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `create_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `create_time` datetime(0) NULL DEFAULT NULL,
  `task_description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `task_type` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `task_path` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `task_questionnaire` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `trigger_questionnaire` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `task_event` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `trigger_event` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `screen_x_y` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `incentive` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `trigger_time` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`task_name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of task
-- ----------------------------
INSERT INTO `task` VALUES ('iii', '小菜无敌', '2024-12-04 17:29:46', 'iii', '原型评估-A类', 'exe/MainPic.exe,exe/TouchTest.exe', '问卷二', '101001', 'i', '101001', '111-111,222-222', '2.json', NULL);
INSERT INTO `task` VALUES ('lll', '小菜无敌', '2024-12-04 17:29:30', 'lll', '原型评估-A类', 'exe/TouchTest.exe', '问卷一', '101001', 'l', '101001', '678-789', '3.json', NULL);
INSERT INTO `task` VALUES ('任务2024-12-4', '小菜无敌', '2024-12-04 17:39:39', '这是任务', '原型评估-A类', 'exe/MainPic.exe,exe/TouchTest.exe', '问卷一', '102001', '事件1', '101001-101002', '111-111,222-222', '1.json', NULL);
INSERT INTO `task` VALUES ('任务一', '小菜无敌', '2024-12-12 17:48:43', '任务一内容描述1', '原型评估-D类', 'exe/MainPic.exe,exe/TouchTest.exe', '问卷二,问卷二', '101008,102001', '事件一,事件二', '102002-102008-203001-203004-102009,101003-101008-202001-202002-202003-101009', '111-222,333-444', '2.json', '00:00:06-00:00:09');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `Id` int(0) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `sex` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `height` double NULL DEFAULT NULL,
  `weight` double NULL DEFAULT NULL,
  `section` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  PRIMARY KEY (`Id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1020 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (1001, '用户1111', '男', 172, 11511, '');
INSERT INTO `user` VALUES (1002, '用户231', '女', 185, 130, '');
INSERT INTO `user` VALUES (1004, '用户3', '女', 185, 161, NULL);
INSERT INTO `user` VALUES (1005, '用户4', '男', 185, 160, NULL);
INSERT INTO `user` VALUES (1006, '用户5', '女', 170, 100, NULL);
INSERT INTO `user` VALUES (1008, '用户6', '女', 170, 115, NULL);
INSERT INTO `user` VALUES (1010, '张博', '男', 165, 123, NULL);
INSERT INTO `user` VALUES (1011, '张好', '男', 167, 123, NULL);
INSERT INTO `user` VALUES (1012, '张波', '男', 175, 123, NULL);
INSERT INTO `user` VALUES (1013, '李一凡', '男', 175, 123, NULL);

SET FOREIGN_KEY_CHECKS = 1;
