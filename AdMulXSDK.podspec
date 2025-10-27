

Pod::Spec.new do |s|
  
  s.name             = 'AdMulXSDK'
  s.version          = '1.0.0'
  s.summary          = 'AdMulXSDK'
  s.homepage         = 'https://github.com/ccly/AdMulXSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'ccly' => '1060108978@qq.com' }
  s.source           = { :git => 'https://github.com/ccly/AdMulXSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '14.0'
  s.vendored_frameworks   = 'AdMulXSDK/AdMulXSDK.xcframework'
  s.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "AVKit", "MessageUI", "QuickLook", "AudioToolBox", "JavaScriptCore", "CoreMotion", "Photos", "LocalAuthentication", "SafariServices", "ImageIO", "CFNetwork", "DeviceCheck", "Quartzcore", "CoreText", "CoreML", "CoreImage", "AudioToolbox", "AppTrackingTransparency", "CoreHaptics"]
  s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi", "xml2", "iconv", "bz2"]
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
end
