# The code he/ she wrote was too complicated for me and I have not learned or had any experiences with Ruby yet.
# Therefore, I just rewrite the code in Ruby from my C++ code by using Google to find the Ruby syntax. 

STDOUT.sync = true 
nb_floors, width, nb_rounds, exit_floor, exit_pos, nb_total_clones, nb_additional_elevators, nb_elevators = gets.split(" ").collect {|x| x.to_i}

map = {}

nb_elevators.times do
    elevator_floor, elevator_pos = gets.split(" ").collect {|x| x.to_i}
    map[elevator_floor] = elevator_pos
end

loop do
    clone_floor, clone_pos, direction = gets.split(" ")
    clone_floor = clone_floor.to_i
    clone_pos = clone_pos.to_i

    if ((clone_floor == exit_floor) && (exit_pos > clone_pos) && (direction == "LEFT")) || ((clone_floor == exit_floor) && (direction == "RIGHT") && (exit_pos < clone_pos))
        puts "BLOCK"
    elsif ((clone_floor == exit_floor) && (direction == "LEFT") && (exit_pos < clone_pos)) || ((clone_floor == exit_floor) && (direction == "RIGHT") && (exit_pos > clone_pos))
        puts "WAIT"
    else
        if ((clone_pos < map[clone_floor].to_i) && (direction == "LEFT")) || ((clone_pos > map[clone_floor].to_i) && (direction == "RIGHT"))
            puts "BLOCK"
        else
            puts "WAIT"
        end
    end
end