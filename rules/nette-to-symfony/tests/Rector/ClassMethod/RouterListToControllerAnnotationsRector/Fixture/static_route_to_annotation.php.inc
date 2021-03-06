<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\RouterListToControllerAnnotationsRetor\Fixture;

use Nette\Application\Routers\RouteList;
use Rector\NetteToSymfony\Tests\Rector\ClassMethod\RouterListToControllerAnnotationsRector\Source\RouteFactory;

final class StaticRouterFactory
{
    public function create(): RouteList
    {
        $routeList = new RouteList();

        // case of single action controller, usually get() or __invoke() method
        $routeList[] = RouteFactory::get('some-path', StaticSomePresenter::class);

        return $routeList;
    }
}

final class StaticSomePresenter
{
    public function run()
    {
    }
}

?>
-----
<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\RouterListToControllerAnnotationsRetor\Fixture;

use Symfony\Component\Routing\Annotation\Route;
use Nette\Application\Routers\RouteList;
use Rector\NetteToSymfony\Tests\Rector\ClassMethod\RouterListToControllerAnnotationsRector\Source\RouteFactory;

final class StaticRouterFactory
{
    public function create(): RouteList
    {
        $routeList = new RouteList();

        return $routeList;
    }
}

final class StaticSomePresenter
{
    /**
     * @Route(path="some-path", methods={"GET"})
     */
    public function run()
    {
    }
}

?>
