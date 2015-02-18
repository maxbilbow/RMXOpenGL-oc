//
//  GameViewController.h
//  OpenGL 3.0
//
//  Created by Max Bilbow on 14/02/2015.
//  Copyright (c) 2015 Rattle Media. All rights reserved.
//
#include <math.h>
#include <GLKit/GLKMatrix4.h>


#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#include "RMXDebugger.h"
#import "Header.h"

@interface GameViewController : GLKViewController
@property (strong,nonatomic) LightSource* sun;// = [[LightSource alloc]init];
@property (strong,nonatomic) Observer * me;
@end
