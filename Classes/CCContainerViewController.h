//
//  ViewController.h
//  CustomControllerContainer
//
//  Created by Charles-Adrien Fournier on 02/04/15.
//  Copyright (c) 2015 Charles-Adrien Fournier. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCBarItem.h"
//#import "UIViewController+CCBarItem.h"

@protocol CCContainerViewControllerDelegate;

typedef NS_ENUM(NSInteger, CCContainerSelectionStyle) {
    CCContainerSelectionStyleOverlay = 1,
    CCContainerSelectionStyleTint = 2
};

typedef NS_ENUM(NSInteger, CCContainerTrasitionAnimationStyle) {
    CCContainerTrasitionAnimationStyleNone,
    CCContainerTrasitionAnimationStyleSlide,
    CCContainerTrasitionAnimationStyleSlideAndScale,
    CCContainerTrasitionAnimationStyleFade
};


@interface CCContainerViewController : UIViewController

- (instancetype)initWithControllers:(NSArray *)controllers;

@property (nonatomic, assign) id<CCContainerViewControllerDelegate>delegate;
@property (nonatomic, copy) NSArray *viewControllers;
@property (nonatomic, assign) UIViewController *selectedViewController;
@property (nonatomic) NSUInteger selectedIndex;


- (void)setViewControllers:(NSArray *)controllers animated:(BOOL)animated;
- (void)setSelectedViewController:(UIViewController *)selectedViewController animated:(BOOL)animate;
- (void)setSelectedIndex:(NSUInteger)selectedIndex animated:(BOOL)animate;

- (CGRect)frameForTabBarItemAtIndex:(NSInteger)index;

@property (nonatomic) BOOL enabledStatusBarBackground;

@property (nonatomic) UIColor *sideBarBackground;
@property (nonatomic) UIColor *buttonSelectedColor;
@property (nonatomic) UIColor *buttonDefaultColor;
@property (nonatomic) UIColor *buttonTextDefaultColor;
@property (nonatomic) UIColor *buttonTextSelectedColor;
@property (nonatomic) UIFont *buttonTextFont;
@property (nonatomic) CGFloat sideBarWidth;
@property (nonatomic) CGFloat buttonSpace;
@property (nonatomic) CGFloat buttonsTopMargin;
@property (nonatomic) CCContainerTrasitionAnimationStyle transitionStyle;
@property (nonatomic) CGFloat transitionScale; //0 to 1
@property (nonatomic) CGFloat transitionDuration;
@property (nonatomic) CGFloat detailCornerRadius;
@property (nonatomic) BOOL enablePopToNavigationRoot;

@property (nonatomic) CCContainerSelectionStyle containerSelectionStyle;

@end

@protocol CCContainerViewControllerDelegate <NSObject>
@optional
- (BOOL)customContainerViewController:(CCContainerViewController*)container shouldSelectViewController:(UIViewController *)viewController;

@end

@interface UIViewController (CCContainer)

@property (nonatomic, retain) CCBarItem *barItem;
@property (nonatomic, readonly) CCContainerViewController *containerViewController;

@end