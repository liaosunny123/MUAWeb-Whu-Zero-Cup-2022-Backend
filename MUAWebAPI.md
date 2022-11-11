---
title: MUAWeb v1.0.0
language_tabs:
  - shell: Shell
  - http: HTTP
  - javascript: JavaScript
  - ruby: Ruby
  - python: Python
  - php: PHP
  - java: Java
  - go: Go
toc_footers: []
includes: []
search: true
code_clipboard: true
highlight_theme: darkula
headingLevel: 2
generator: "@tarslib/widdershins v4.0.15"

---

# MUAWeb

> v1.0.0

# 用户

## POST 登录请求

POST /auth/login

用于用户登录请求，且同账号登录时的逻辑为：前一个用户被登出，异地登录的账号可以正常登录。此时第一个用户的Token被吊销。

> Body 请求参数

```json
{
  "username": "%!5IDsFUPC",
  "passwd": "K68P@0[9WCa!SK"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» passwd|body|string| 是 |明文传输|

> 返回示例

> 成功

```json
{
  "status": false,
  "token": "dolorereprehenderit"
}
```

> 禁止访问

```json
{
  "code": 403,
  "cause": "未匹配的用户账号和密码"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|
|403|[Forbidden](https://tools.ietf.org/html/rfc7231#section-6.5.3)|禁止访问|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||状态，为True表示登录成功|
|» token|string|true|none||True时返回Token|

状态码 **403**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» code|integer|true|none||错误代码：403|
|» cause|string|true|none||原因|

## POST 注册用户

POST /auth/register

如果注册用户已存在，那么会提示异常

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "reg_username": "string",
  "reg_password": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» reg_username|body|string| 是 |被注册的用户名|
|» reg_password|body|string| 是 |被注册的密码|

> 返回示例

> 删除成功

```json
{}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|204|[No Content](https://tools.ietf.org/html/rfc7231#section-6.3.5)|删除成功|Inline|

### 返回数据结构

## POST 修改密码

POST /auth/editPassword

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "newpassword": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» newpassword|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 修改他人密码

POST /auth/editUserPassword

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "targetuser": "string",
  "targetpassword": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» targetuser|body|string| 是 |none|
|» targetpassword|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 删除用户

POST /auth/removeUser

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "targetusername": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» targetusername|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 吊销密钥

POST /auth/disposeToken

吊销密钥发送后，密钥会立即被吊销，此时前端需要处理用户登出事宜。

> Body 请求参数

```json
{
  "username": "string",
  "token": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 刷新Token

POST /auth/refreshToken

刷新Token，且Token有效时才会进行刷新。每一个Token自生成/刷新后有24小时的存活周期，若24小时内没有被刷新那么视为自动吊销Token.

> Body 请求参数

```json
{
  "username": "string",
  "token": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|string|true|none||none|

# 内容

## GET 获取学校列表

GET /school/getSchoolList

学校列表的Pid为文章的特定识别码，需要储存Pid信息

> 返回示例

> 200 Response

```json
{
  "school": {
    "pid": 0,
    "name": "string",
    "img": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» school|object|true|none||none|
|»» pid|integer|true|none||none|
|»» name|string|true|none||none|
|»» img|string|true|none||none|

## GET 获取学校内容

GET /school/getSchoolContent/{pid}

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|pid|path|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "title": "string",
  "content": "string",
  "time": "string",
  "author": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» title|string|true|none||none|
|» content|string|true|none||none|
|» time|string|true|none||none|
|» author|string|true|none||none|

## POST 创建学校

POST /school/createSchool

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "school": {
    "title": "string",
    "createtime": "string",
    "content": "string",
    "img": "string"
  }
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» school|body|object| 是 |none|
|»» title|body|string| 是 |none|
|»» createtime|body|string| 是 |none|
|»» content|body|string| 是 |none|
|»» img|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|string|true|none||none|

## POST 创建文章

POST /passage/createPassage

category:
1.school【保留参数，不可使用】
2.项目列表
3.复原计划
4.活动介绍
5.其它

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "category": "string",
  "Passage": {
    "title": "string",
    "createtime": "string",
    "content": "string"
  }
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» category|body|string| 是 |none|
|» Passage|body|object| 是 |none|
|»» title|body|string| 是 |none|
|»» createtime|body|string| 是 |none|
|»» content|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|string|true|none||none|

## GET 获取文章列表

GET /passage/getPassageList/{category}

category:
1.school【保留参数，不可使用】
2.项目列表
3.复原计划
4.活动介绍
5.其它

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|category|path|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "passage": {
    "pid": 0,
    "name": "string",
    "author": "string",
    "time": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» passage|object|true|none||none|
|»» pid|integer|true|none||none|
|»» name|string|true|none||none|
|»» author|string|true|none||none|
|»» time|string|true|none||none|

## GET 获取文章内容

GET /passage/getPassageContent/{category}/{pid}

category:
1.school【保留参数，不可使用】
2.项目列表
3.复原计划
4.活动介绍
5.其它

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|category|path|integer| 是 |none|
|pid|path|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "title": "string",
  "author": "string",
  "content": "string",
  "time": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» title|string|true|none||none|
|» author|string|true|none||none|
|» content|string|true|none||none|
|» time|string|true|none||none|

## GET 获取Banner

GET /banner/getBanner/{position}

position:
1.IndexHeader:首页

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|position|path|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "banner": {
    "pid": 0,
    "img": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» banner|object|true|none||none|
|»» pid|integer|true|none||none|
|»» img|string|true|none||none|

## GET 获取时光机

GET /timeline/getTimeline

> 返回示例

> 200 Response

```json
{
  "timeline": {
    "pid": 0,
    "name": "string",
    "description": "string",
    "time": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» timeline|object|true|none||none|
|»» pid|integer|true|none||none|
|»» name|string|true|none||none|
|»» description|string|true|none||none|
|»» time|string|true|none||none|

## POST 创建时光机

POST /timeline/createTimeline

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "name": "string",
  "description": "string",
  "time": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» name|body|string| 是 |none|
|» description|body|string| 是 |none|
|» time|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": "string"
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|string|true|none||none|

## GET 分表查询

GET /search/for

请求分页表，需要在Json内增加参数：
limitby:分页数，如20，40，即将结果集以多少页分开
orderlist:页数，如1，2，即请求分页表的第几页

> Body 请求参数

```json
{
  "limitby": "string",
  "orderlist": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|q|query|string| 是 |none|
|body|body|object| 否 |none|
|» limitby|body|string| 是 |none|
|» orderlist|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "passage": {
    "author": "string",
    "name": "string",
    "title": "string",
    "pid": "string",
    "category": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» passage|object|true|none||none|
|»» author|string|true|none||none|
|»» name|string|true|none||none|
|»» title|string|true|none||none|
|»» pid|string|true|none||none|
|»» category|string|true|none||none|

## POST 删除学校

POST /school/removeSchool

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "pid": 0
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» pid|body|integer| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 删除文章

POST /passage/removePassage

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "category": "string",
  "pid": 0
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» category|body|string| 是 |none|
|» pid|body|integer| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 删除时光机

POST /timeline/removeTimeline

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "pid": 0
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» pid|body|integer| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 删除banner

POST /banner/removeBanner

position:
1.IndexHeader:首页

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "pid": 0,
  "position": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» pid|body|integer| 是 |none|
|» position|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## POST 创建Banner

POST /banner/createBanner

> Body 请求参数

```json
{
  "username": "string",
  "token": "string",
  "img": "string",
  "position": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|body|body|object| 否 |none|
|» username|body|string| 是 |none|
|» token|body|string| 是 |none|
|» img|body|string| 是 |none|
|» position|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "status": true
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» status|boolean|true|none||none|

## GET 查询

GET /search/co

> Body 请求参数

```json
{
  "limitby": "string",
  "orderlist": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|q|query|string| 是 |none|
|body|body|object| 否 |none|
|» limitby|body|string| 是 |none|
|» orderlist|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "passage": {
    "author": "string",
    "name": "string",
    "title": "string",
    "pid": "string",
    "category": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» passage|object|true|none||none|
|»» author|string|true|none||none|
|»» name|string|true|none||none|
|»» title|string|true|none||none|
|»» pid|string|true|none||none|
|»» category|string|true|none||none|

## GET 强制查询

GET /search/cof

使用强制查询将禁止后端从缓存中读取查询结果集（即最新的结果）
【本API将会在后端完成缓存集动态更新模块后取消！】

> Body 请求参数

```json
{
  "limitby": "string",
  "orderlist": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|q|query|string| 是 |none|
|body|body|object| 否 |none|
|» limitby|body|string| 是 |none|
|» orderlist|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "passage": {
    "author": "string",
    "name": "string",
    "title": "string",
    "pid": "string",
    "category": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» passage|object|true|none||none|
|»» author|string|true|none||none|
|»» name|string|true|none||none|
|»» title|string|true|none||none|
|»» pid|string|true|none||none|
|»» category|string|true|none||none|

## GET 强制分表查询

GET /search/forf

使用强制查询将禁止后端从缓存中读取查询结果集（即最新的结果）
【本API将会在后端完成缓存集动态更新模块后取消！】
请求分页表，需要在Json内增加参数：
limitby:分页数，如20，40，即将结果集以多少页分开
orderlist:页数，如1，2，即请求分页表的第几页

> Body 请求参数

```json
{
  "limitby": "string",
  "orderlist": "string"
}
```

### 请求参数

|名称|位置|类型|必选|说明|
|---|---|---|---|---|
|q|query|string| 是 |none|
|body|body|object| 否 |none|
|» limitby|body|string| 是 |none|
|» orderlist|body|string| 是 |none|

> 返回示例

> 200 Response

```json
{
  "passage": {
    "author": "string",
    "name": "string",
    "title": "string",
    "pid": "string",
    "category": "string"
  }
}
```

### 返回结果

|状态码|状态码含义|说明|数据模型|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|成功|Inline|

### 返回数据结构

状态码 **200**

|名称|类型|必选|约束|中文名|说明|
|---|---|---|---|---|---|
|» passage|object|true|none||none|
|»» author|string|true|none||none|
|»» name|string|true|none||none|
|»» title|string|true|none||none|
|»» pid|string|true|none||none|
|»» category|string|true|none||none|

# 数据模型

