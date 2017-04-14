require "yaml"
require 'pp'
require 'erb'

commands = YAML.load(IO.read('commands.yml'))

commands.each do |c|
  rawname = c['name'][1..-1]
  c[:cmdname] = "CMD_"+rawname.upcase
  c[:klass] = "#{rawname[0].capitalize}#{rawname[1..-1]}Message"
end

pp commands

TYPE_MAP = {
  'float' => 'float ',
  'string' => 'QString *',
  'id_pen' => 'uint16_t ',
  'id_brush' => 'uint16_t ',
}

def gen_erb(template, b)
  file = "script/#{template}.erb"
  e = ERB.new(IO.read(file))
  e.filename = file
  out = e.result(b)
  outfile = "gen/#{template}"
  File.open(outfile,'w') do |f|
    f.print out
  end
end

TEMPLATES = [
  'messages.h'
]

b = binding
TEMPLATES.each do |t|
  gen_erb(t,b)
end
