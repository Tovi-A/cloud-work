import pymongo
myclient = pymongo.MongoClient("mongodb://mongo-0.mongo-glusterfs.default.svc.cluster.local:27017/")
mydb = myclient["mongo_test"]
mycol = mydb["set_test"]

dblist = myclient.list_database_names()
if "mongo_test" in dblist:
  print("数据库mongo_test已存在！")

collist = mydb.list_collection_names()
if "set_test" in collist:
  print("集合已存在！")

mylist = [
  { "name": "Taobao", "alexa": "100", "url": "https://www.taobao.com" },
  { "name": "QQ", "alexa": "101", "url": "https://www.qq.com" },
  { "name": "Facebook", "alexa": "10", "url": "https://www.facebook.com" },
  { "name": "知乎", "alexa": "103", "url": "https://www.zhihu.com" },
  { "name": "Github", "alexa": "109", "url": "https://www.github.com" }
]

# 向set_test集合插入数据 
x = mycol.insert_many(mylist)

# 查询set_test集合中所有数据
for x in mycol.find():
  print(x)

myquery = { "name": "Taobao" }
 
mycol.delete_one(myquery)
 
# 删除后输出
for x in mycol.find():
  print(x)

