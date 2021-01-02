forest = File.read("input.txt").split.map { |x| x.chars }
EMPTY = "."
TREE = "#"

forest_size = forest.length
forest_length = forest.first.length

y = 0
x = 0

y_step = 1
x_step = 3

def calculate_index(arr, index)
  return index % arr.length 
end

tree_count = 0
while y < forest_size
  if forest[y][calculate_index(forest[y], x)] == TREE
    tree_count += 1 
  end 
  x += x_step
  y += y_step
end

puts tree_count
