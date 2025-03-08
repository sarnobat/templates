-- USAGE
-- find -L  / |  ./helloworld.hs.bin
main:: IO ()
main = loop

loop:: IO ()
loop = do
  line <- getLine
  if null line
    then return ()
    else do
      putStrLn ("You entered: " ++ line)
      loop
-- main :: IO ()
-- main = interact process
--   where
--     process :: String -> String
--     process input = map toUpper input
-- 	putStrLn input
