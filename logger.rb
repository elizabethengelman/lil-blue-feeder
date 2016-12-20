require 'serialport'

class Logger
  PORT = '/dev/tty.usbmodem1411'
  BAUD_RATE = 9600
  DATA_BITS = 8
  STOP_BITS = 1
  PARITY = SerialPort::NONE

  def start
    puts "Startinglogger"
    log_loop
  end

  def serial_port
    SerialPort.new(PORT, BAUD_RATE, DATA_BITS, STOP_BITS, PARITY)
  end

  def log_loop
    while true do
      while(i = serial_port.gets.chomp) do
        write_to_file(i)
        puts i
      end
    end
  end

  def write_to_file(event)
    log_entry = "#{Time.now}: #{event}\n"
    File.open('lil_b_feeder.log', 'a') do |file|
      file.write(log_entry)
    end
  end
end

Logger.new.start
