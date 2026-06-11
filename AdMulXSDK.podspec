

Pod::Spec.new do |s|
  
  s.name                   = 'AdMulXSDK'
  s.version                = '1.0.9.00.3'
  s.summary                = 'AdMulXSDK'
  s.homepage               = 'https://github.com/ccly/AdMulXSDK'
  s.license                = { :type => 'MIT', :file => 'LICENSE' }
  s.author                 = { 'ccly' => '1060108978@qq.com' }
  s.source                 = { :git => 'https://github.com/ccly/AdMulXSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target  = '11.0'
  s.vendored_frameworks    = 'AdMulXSDK/AdMulXSDK.xcframework'
  s.resource = 'AdMulXSDK/AdMulXSDK.bundle'
  s.dependency 'GDTMobSDK', '4.15.90'
  s.dependency 'KSAdSDK', '5.4.10.1'
  s.dependency 'SigmobAd-iOS', '4.20.22'
  s.dependency 'OctopusSDK', '2.6.5.15'
  s.dependency 'MSMobAdSDKv3','3.0.10.2'
  s.dependency 'AdGainSDK', '4.2.7.3'
  s.dependency 'AdWangMaiSDK', '7.9.4.35'
  s.dependency 'MentaVlionBaseSDK', '7.00.28'
  s.dependency 'MentaUnifiedSDK', '7.00.28'
  s.dependency 'MentaVlionSDK', '7.00.28'
  s.dependency 'MentaVlionAdapter', '7.00.28'
  s.dependency 'LitemobAd', '1.0.9'
  s.dependency 'YFAdsSDK/YFAdsSDK', '6.1.2.1'
  
  s.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "AVKit", "MessageUI", "QuickLook", "AudioToolBox", "JavaScriptCore", "CoreMotion", "Photos", "LocalAuthentication", "SafariServices", "ImageIO", "CFNetwork", "DeviceCheck", "Quartzcore", "CoreText", "CoreML", "CoreImage", "AudioToolbox", "AppTrackingTransparency", "CoreHaptics"]
  s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi", "xml2", "iconv", "bz2"]
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.swift_versions = ['5']

end
