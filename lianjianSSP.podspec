Pod::Spec.new do |s|
  s.name         = "lianjianSSP"
  s.version      = "1.0.0.1"
  s.summary      = "SDK for Advertisement"
  s.description  = <<-DESC
A long Descriptiion of lianjianSSP
                       DESC
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.homepage     = "https://github.com/OrisForest/lianjianSSP";
  s.author       = { "崔鹏" => "365473321@qq.com" }
  s.ios.deployment_target = '8.0'
  s.source       = { :git => "https://github.com/OrisForest/lianjianSSP.git", :tag => "#{s.version}" }
  s.resource = 'lianjianSSP.framework/LSResource.bundle'

  s.vendored_frameworks = 'lianjianSSP.framework'

  s.requires_arc = true
end