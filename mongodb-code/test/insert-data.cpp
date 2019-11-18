import pymongo
myclient = pymongo.MongoClient("mongodb://mongo-0.mongo-glusterfs.default.svc.cluster.local:27017/")
mydb = myclient["mongo_test"]
mycol = mydb["sites"]

mylist = [
  { "name": "Taobao", "alexa": "100", "url": "https://www.taobao.com" },
  { "name": "QQ", "alexa": "101", "url": "https://www.qq.com" },
  { "name": "Facebook", "alexa": "10", "url": "https://www.facebook.com" },
  { "name": "知乎", "alexa": "103", "url": "https://www.zhihu.com" },
  { "name": "Github", "alexa": "109", "url": "https://www.github.com" }
]

# 向sites集合插入数据 
x = mycol.insert_many(mylist)

mycol = mydb["info"]

mylist = [
  {"name": "zhangsan", "age": 24},
  {"name": "lisi", "age": 23}
]

# 向info集合插入数据 
y = mycol.insert_many(mylist)
# 输出插入的所有文档对应的 _id 值
print(x.inserted_ids)

if "test" in myclient.list_database_names():
  print("test数据库已存在！")

# 查询sites集合中所有数据
for x in mycol.find():
  print(x)

