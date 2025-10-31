//
//  WFFCustomDevProtocol.h
//  WindFoundation
//
//  Created by Codi on 2022/11/22.
//

@protocol WFFCustomDevProtocol <NSObject>

/**
 * 是否允许SDK主动使用地理位置信息
 *
 * @return YES可以获取，NO禁止获取
 */
- (BOOL)isCanUseLocation;

/**
 * 当isCanUseLocation=NO时，可传入地理位置信息，sdk使用您传入的地理位置信息
 *
 * @return 地理位置参数
 */

- (NSValue *)getLocation;

/**
 * 是否允许SDK主动获取IDFA信息
 *
 * @return YES可以获取，NO禁止获取。默认为YES
 */
- (BOOL)isCanUseIdfa;

/**
 * 当isCanUseIdfa=NO时，可传入idfa信息。sdk使用您传入的idfa信息
 *
 * @return idfa设备信息
 */
- (NSString *)getDevIdfa;

/**
 * 是否允许SDK主动获取IDFV信息
 *
 * @return YES可以获取，NO禁止获取。默认为YES
 */
- (BOOL)isCanUseIdfv;

/**
 * 当isCanUseIdfv=NO时，可传入idfv信息。sdk使用您传入的idfv信息
 *
 * @return idfv设备信息
 */
- (NSString *)getDevIdfv;

/**
 * 是否允许SDK主动使用互动组件（摇一摇、扭一扭等）
 *
 * @return YES可以使用，NO禁止使用。默认为YES
 */
- (BOOL)isCanUseMotionManager;

@end
