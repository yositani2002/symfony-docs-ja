by_reference
~~~~~~~~~~~~

**データ型type**: ``Boolean`` **デフォルト**: ``true``

ほとんどの場合、\ ``name`` フィールドを持つとすると、基礎となるオブジェクトで ``setName`` が呼ばれることを期待します。
しかし、場合によっては ``setName`` は呼ばれ *ない* ことがあります。\ ``by_reference`` をセットすることですべての場合にセッターが呼ばれます。
In most cases, if you have a ``name`` field, then you expect ``setName``
to be called on the underlying object. In some cases, however, ``setName``
may *not* be called. Setting ``by_reference`` ensures that the setter is
called in all cases.

さらに説明するための簡単な例がこちらです。::
To explain this further, here's a simple example::

    $builder = $this->createFormBuilder($article);
    $builder
        ->add('title', 'text')
        ->add(
            $builder->create('author', 'form', array('by_reference' => ?))
                ->add('name', 'text')
                ->add('email', 'email')
        )

``by_reference`` を ``true`` にした場合、フォームの ``submit`` （または ``handleRequest`` ）が呼ばれたとき、次のように裏側では処理されます。::
If ``by_reference`` is true, the following takes place behind the scenes
when you call ``submit`` (or ``handleRequest``) on the form::

    $article->setTitle('...');
    $article->getAuthor()->setName('...');
    $article->getAuthor()->setEmail('...');

``setAuthor`` が呼び出されないことに注意して下さい。\ ``author`` は参照により編集されます。
Notice that ``setAuthor`` is not called. The author is modified by reference.

``by_reference`` を ``false`` にした場合、送信のときはこのようになります。::
If you set ``by_reference`` to false, submitting looks like this::

    $article->setTitle('...');
    $author = $article->getAuthor();
    $author->setName('...');
    $author->setEmail('...');
    $article->setAuthor($author);

``by_reference=false`` が実際にするすべては、親オブジェクトのセッターを呼ぶことをフレームワークに強制することです。
So, all that ``by_reference=false`` really does is force the framework to
call the setter on the parent object.

:doc:`collection</reference/forms/types/collection>` フォームタイプを利用している場合と同様に、基礎となるコレクションデータは（ Doctrine の ``ArrayCollection`` のように）オブジェクトです。そして、（例えば ``setAuthors`` のように）セッターが呼ばれる必要がある場合、\ ``by_reference`` は ``false`` に設定されるべきです。
Similarly, if you're using the :doc:`collection</reference/forms/types/collection>`
form type where your underlying collection data is an object (like with Doctrine's
``ArrayCollection``), then ``by_reference`` must be set to ``false`` if you
need the setter (e.g. ``setAuthors``) to be called.

.. 2014/01/11 yositani2002 50cd5c32a49376dd2b76b9a85cb7becc9967f79a
