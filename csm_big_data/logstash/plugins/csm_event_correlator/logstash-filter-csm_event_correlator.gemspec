Gem::Specification.new do |s|
  s.name = 'logstash-filter-csm-event-correlator'
  s.version         = "0.2.0"
  s.licenses = ["Eclipse Public License v1.0"]
  s.summary = "A filter for generating RAS events in response to log patterns."
  s.description     = "This gem is a Logstash plugin required to be installed on top of the Logstash core pipeline using $LS_HOME/bin/logstash-plugin install gemname. This gem is not a stand-alone program."
  s.authors = ["John Dunham"]
  s.email = "jdunham@us.ibm.com"
  s.homepage = "https://github.com/IBM/CAST"
  s.require_paths = ["lib"]

  # Files
  s.files = Dir['lib/**/*','spec/**/*','vendor/**/*','*.gemspec','*.md','CONTRIBUTORS','Gemfile','LICENSE','NOTICE.TXT']
   # Tests
  s.test_files = s.files.grep(%r{^(test|spec|features)/})

  # Special flag to let us know this is actually a logstash plugin
  s.metadata = { "logstash_plugin" => "true", "logstash_group" => "output" }

  # Gem dependencies
  s.add_runtime_dependency "logstash-core"
  s.add_runtime_dependency "logstash-codec-plain"
  s.add_development_dependency "logstash-devutils"
end
