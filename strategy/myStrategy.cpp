/*****************************************************************************
 *  C++ 设计模式之策略模式
 *  Copyright (C) 2020 1158292387@qq.com
 *
 *  @file     main.cpp
 *  @brief    对文件的简述
 *  Details.
 *
 *  @author   Leeme
 *  @email    1158292387@qq.com
 *  @version  1.0.0.1(版本号)
 *  @date     2020.11.11
 *  @license  GNU General Public License (GPL)
 *
 *----------------------------------------------------------------------------
 *  Remark         : Description
 *----------------------------------------------------------------------------
 *  Change History :
 *  <Date>     | <Version> | <Author>       | <Description>
 *----------------------------------------------------------------------------
 *  2020/10/30 | 1.0.0.1   | Leeme          | Create file
 *----------------------------------------------------------------------------
 *
 *****************************************************************************/

/*****************************************************************************
 *  C++ 设计模式之策略模式
 *  Copyright (C) 2020 1158292387@qq.com
 *
 *  @file     Strategy.h
 *  @brief    对文件的简述
 *  Details.
 *
 *  @author   Leeme
 *  @email    1158292387@qq.com
 *  @version  1.0.0.1(版本号)
 *  @date     2020.11.11
 *  @license  GNU General Public License (GPL)
 *
 *----------------------------------------------------------------------------
 *  Remark         : Description
 *----------------------------------------------------------------------------
 *  Change History :
 *  <Date>     | <Version> | <Author>       | <Description>
 *----------------------------------------------------------------------------
 *  2020/10/30 | 1.0.0.1   | Leeme          | Create file
 *----------------------------------------------------------------------------
 *
 *****************************************************************************/
#pragma once
#include <iostream>

/**
 * @brief 简单概述
 * @brief 操作基类
 */
class Operation {
public:
  Operation() {}
  ~Operation() {}

  virtual void OperOutput() = 0;
};

/**
 * @brief 简单概述
 * @brief 合并图像操作
 */
class MergeOper : public Operation {
public:
  MergeOper() : Operation() {}
  ~MergeOper() {}

  void OperOutput() { std::cout << "Merge Image" << std::endl; }
};

/**
 * @brief 简单概述
 * @brief 剪切图像操作
 */
class ClipOper : public Operation {
public:
  ClipOper() {}
  ~ClipOper() {}

  void OperOutput() { std::cout << "Clip Image" << std::endl; }
};

/**
 * @brief 简单概述
 * @brief 缩放图像操作
 */
class ScaleOper : public Operation {
public:
  ScaleOper() : Operation() {}
  ~ScaleOper() {}

  void OperOutput() { std::cout << "Scale Image" << std::endl; }
};

/**
 * @brief 简单概述
 * @brief 图像基类
 */
class Image {
public:
  Image(Operation *oper) : m_pOper(oper) {}
  ~Image() {}

  virtual void OperOutput() { m_pOper->OperOutput(); }

protected:
  Operation *m_pOper;
};

/**
 * @brief 简单概述
 * @brief 灰度图像类
 */
class GreyImage : public Image {
public:
  GreyImage(Operation *oper) : Image(oper) {}
  ~GreyImage() {}

  virtual void OperOutput() {
    std::cout << "I am GreyImage." << std::endl;
    Image::OperOutput();
  }
};

/**
 * @brief 简单概述
 * @brief RGB图像类
 */
class RgbImage : public Image {
public:
  RgbImage(Operation *oper) : Image(oper) {}
  ~RgbImage() {}

  virtual void OperOutput() {
    std::cout << "I am RgbImage." << std::endl;
    Image::OperOutput();
  }
};

/**
 * @brief 简单概述
 * @brief HSV图像类
 */
class HsvImage : public Image {
public:
  HsvImage(Operation *oper) : Image(oper) {}
  ~HsvImage() {}

  virtual void OperOutput() {
    std::cout << "I am HsvImage." << std::endl;
    Image::OperOutput();
  }
};

int main(int argc, char *argv[]) {
  MergeOper mOper;
  ClipOper cOper;
  ScaleOper sOper;

  GreyImage greyImg(&mOper);
  greyImg.OperOutput();

  RgbImage rgbImg(&cOper);
  rgbImg.OperOutput();

  HsvImage hsvImg(&sOper);
  hsvImg.OperOutput();

  GreyImage mGreyImg(&cOper);
  mGreyImg.OperOutput();

  std::cout << std::endl;
  for (size_t i = 0; i < 1; i++) {
    std::cout << "* ** *** **** ***** ****** *******" << std::endl;
    std::cout << "** *** **** ***** ****** ******* *" << std::endl;
    std::cout << "*** **** ***** ****** ******* * **" << std::endl;
    std::cout << "**** ***** ****** ******* * ** ***" << std::endl;
    std::cout << "**** **** **** <==> **** **** ****" << std::endl;
    std::cout << "***** ****** ******* * ** *** ****" << std::endl;
    std::cout << "****** ******* * ** *** **** *****" << std::endl;
    std::cout << "******* * ** *** **** ***** ******" << std::endl;
    std::cout << "* ** *** **** ***** ****** *******" << std::endl;
  }
  std::cout << std::endl;

  std::cout << "<<<<<<<<== Hello! You are a good man! ==>>>>>>>" << std::endl;
  getchar();
  return 0;
}