forest = File.read("input.txt").split.map { |x| x.chars }

def calculate_index(arr, index)
  return index % arr.length 
end

def check_path(x_step, y_step, forest)
  forest_size = forest.length
  forest_length = forest.first.length
  tree_count = 0
  x = 0
  y = 0
  while y < forest_size
    if forest[y][calculate_index(forest[y], x)] == "#"
      tree_count += 1 
    end 
    x += x_step
    y += y_step
  end
  return tree_count
end

trees = [[1, 1], [3, 1], [5, 1], [7, 1], [1, 2]].map do |pair|
  x = pair.first
  y = pair.last
  check_path(x, y, forest)
end
puts trees.reduce(:*)
