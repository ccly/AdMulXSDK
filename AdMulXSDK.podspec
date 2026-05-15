

Pod::Spec.new do |s|
  
  s.name                   = 'AdMulXSDK'
  s.version                = '1.0.7.01'
  s.summary                = 'AdMulXSDK'
  s.homepage               = 'https://github.com/ccly/AdMulXSDK'
  s.license                = { :type => 'MIT', :file => 'LICENSE' }
  s.author                 = { 'ccly' => '1060108978@qq.com' }
  s.source                 = { :git => 'https://github.com/ccly/AdMulXSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target  = '11.0'
  s.vendored_frameworks    = 'AdMulXSDK/AdMulXSDK.xcframework'
  s.resource = 'AdMulXSDK/AdMulXSDK.bundle'
  s.dependency 'GDTMobSDK', '4.15.80'
  s.dependency 'KSAdSDK', '5.3.20.1'
  s.dependency 'SigmobAd-iOS', '4.20.10'
  s.dependency 'OctopusSDK', '2.6.4.20'
  s.dependency 'MSMobAdSDKv3','3.0.9.1'
  s.dependency 'AdGainSDK', '4.2.7.1'
  s.dependency 'AdWangMaiSDK', '7.8.4.32'
  s.dependency 'BaiduMobAdSDK', '10.050'
  s.dependency 'MentaVlionBaseSDK', '7.00.24'
  s.dependency 'MentaUnifiedSDK', '7.00.24'
  s.dependency 'MentaVlionSDK', '7.00.24'
  s.dependency 'MentaVlionAdapter', '7.00.24'
  s.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "AVKit", "MessageUI", "QuickLook", "AudioToolBox", "JavaScriptCore", "CoreMotion", "Photos", "LocalAuthentication", "SafariServices", "ImageIO", "CFNetwork", "DeviceCheck", "Quartzcore", "CoreText", "CoreML", "CoreImage", "AudioToolbox", "AppTrackingTransparency", "CoreHaptics"]
  s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi", "xml2", "iconv", "bz2"]
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
end
