#
# Be sure to run `pod lib lint PJSIP-IOS-lib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PJSIP-IOS-lib'
  s.version          = '0.1.0'
  s.summary          = 'Useful pod for PJSIP'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/tiana890/PJSIP-IOS-lib.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'tiana890' => 'marinazayceva89@gmail.com' }
  s.source           = { :git => 'https://github.com/tiana890/PJSIP-IOS-lib.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

s.source_files = 'PJSIP-IOS-lib/Classes/**/*.{h, hpp}'
  s.libraries 			= 'stdc++'
  # s.resource_bundles = {
  #   'PJSIP-IOS-lib' => ['PJSIP-IOS-lib/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/include/*.h'
   s.frameworks = "AudioToolbox", "AVFoundation", "CFNetwork",  "CoreMedia"
  # s.dependency 'AFNetworking', '~> 2.3'

    s.xcconfig = {
    'GCC_PREPROCESSOR_DEFINITIONS' => 'PJ_AUTOCONF=1',
    'HEADER_SEARCH_PATHS'  => '$(inherited) $(PODS_ROOT)/PJSIP-IOS-lib/'
    }
end
